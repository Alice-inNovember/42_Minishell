/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:19:28 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/06 15:38:03 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int	g_last_exit_status;

int	check_and_exec_single_builtin(t_data *data, t_list *envp_list)
{
	t_proc_data		*proc_data;
	t_builtin_fp	bt_fp;
	char			**cmd_argv;
	int				origin_io[2];

	proc_data = list_peek_first_content(&data->proc_data_list);
	cmd_argv = cmd_list2arr(&proc_data->cmd_list);
	bt_fp = builtin_find(&data->builtin_list, cmd_argv[0]);
	if (list_size(&data->proc_data_list) == 1 && bt_fp != NULL)
	{
		origin_io[READ_END] = dup(STDIN_FILENO);
		origin_io[WRITE_END] = dup(STDOUT_FILENO);
		do_redirect(proc_data);
		bt_fp(cmd_argv, envp_list);
		cmd_argv_free(cmd_argv);
		dup2(origin_io[READ_END], STDIN_FILENO);
		dup2(origin_io[WRITE_END], STDOUT_FILENO);
		close(origin_io[READ_END]);
		close(origin_io[WRITE_END]);
		return (1);
	}
	return (0);
}

void	wait_child(t_data *data)
{
	t_node	*node;
	int		status;

	node = list_peek_first_node(&data->pid_list);
	while (node->next != NULL)
	{
		waitpid(*((pid_t *)node->content), &status, 0);
		g_last_exit_status = wexitstatus(status);
		node = node->next;
	}
}

pid_t	do_fork(t_data *data, t_proc_data *proc_data)
{
	pid_t		pid;
	int			pip[2];
	int			pipe_stat;
	int			cur_write_end;
	static int	prev_read_end = -1;

	if (prev_read_end == -1)
		prev_read_end = 0;
	if (is_last_cmd(data, proc_data))
		cur_write_end = STDOUT_FILENO;
	else
	{
		pipe_stat = pipe(pip);
		if (pipe_stat != 0)
			(wait_child(data), perror("minishell"), exit(EXIT_FAILURE));
		cur_write_end = pip[WRITE_END];
	}
	pid = fork();
	if (pid == 0)
		execute_child(data, proc_data, cur_write_end, prev_read_end);
	if (prev_read_end != -1)
		close(prev_read_end);
	prev_read_end = pip[0];
	if (!is_last_cmd(data, proc_data))
		close(pip[WRITE_END]);
	return (pid);
}

void	make_child(t_data *data)
{
	t_node	*proc_node;
	pid_t	pid;

	proc_node = list_peek_first_node(&data->proc_data_list);
	while (proc_node->next != NULL)
	{
		pid = do_fork(data, proc_node->content);
		pid_list_add(&data->pid_list, pid);
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
