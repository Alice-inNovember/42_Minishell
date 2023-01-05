/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:19:28 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/05 10:33:36 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <unistd.h>

int	check_and_exec_single_builtin(t_data *data, t_list *envp_list)
{
	t_proc_data		*proc_data;
	t_builtin_fp	bt_fp;
	int				stdpip[2];
	int				prev_stdio[2];
	char			**cmd_argv;

	proc_data = list_peek_first_content(&data->proc_data_list);
	cmd_argv = cmd_list2arr(&proc_data->cmd_list);
	bt_fp = builtin_find(&data->builtin_list, cmd_argv[0]);
	stdpip[1] = STDOUT_FILENO;
	if (list_size(&data->proc_data_list) == 1 && bt_fp != NULL)
	{
		prev_stdio[0] = dup(STDIN_FILENO);
		prev_stdio[1] = dup(STDOUT_FILENO);
		child_redirect(proc_data, stdpip, 0);
		bt_fp(cmd_argv, envp_list);
		dup2(prev_stdio[0], STDIN_FILENO);
		dup2(prev_stdio[1], STDOUT_FILENO);
		close(prev_stdio[0]);
		close(prev_stdio[1]);
		cmd_argv_free(cmd_argv);
		return (1);
	}
	return (0);
}

void	wait_child(t_data *data)
{
	t_node	*pid_node;

	pid_node = list_peek_first_node(&data->pid_list);
	while (pid_node != NULL)
	{
		waitpid(*(pid_t *)pid_node->content, &g_last_exit_status, 0);
		pid_node = pid_node->next;
	}
}

pid_t	do_fork(t_data *data, t_proc_data *proc_data)
{
	pid_t		pid;
	int			pip[2];
	int			pipe_stat;
	static int	prev_read_end = -1;

	if (prev_read_end != -1)
		close(prev_read_end);
	pipe_stat = pipe(pip);
	if (pipe_stat != 0)
	{
		wait_child(data);
		perror("minishell");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == 0)
		execute_child(data, proc_data, pip, prev_read_end);
	prev_read_end = pip[0];
	close(pip[1]);
	return (pid);
}

void	make_child(t_data *data)
{
	t_node	*proc_node;
	pid_t	*pid;

	proc_node = list_peek_first_node(&data->proc_data_list);
	while (proc_node->next != NULL)
	{
		pid = ft_calloc(1, sizeof(pid_t));
		*pid = do_fork(data, proc_node->content);
		list_append(&data->pid_list, (void *)pid);
		proc_node = proc_node->next;
	}
}

void	executor(t_data *data)
{
	if (data->syntax_err_flag != E_NONE)
		return ;
	if (check_and_exec_single_builtin(data, &data->envp_list))
		return ;
	make_child(data);
	wait_child(data);
}
