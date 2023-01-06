/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:19:28 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/06 09:02:50 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdio.h>
#include <unistd.h>

int	check_and_exec_single_builtin(t_data *data, t_list *envp_list)
{
	t_proc_data		*proc_data;
	t_builtin_fp	bt_fp;
	char			**cmd_argv;

	proc_data = list_peek_first_content(&data->proc_data_list);
	cmd_argv = cmd_list2arr(&proc_data->cmd_list);
	bt_fp = builtin_find(&data->builtin_list, cmd_argv[0]);
	if (list_size(&data->proc_data_list) == 1 && bt_fp != NULL)
	{
		bt_fp(cmd_argv, envp_list);
		cmd_argv_free(cmd_argv);
		return (1);
	}
	return (0);
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
		//wait_child(data);
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
		do_fork(data, proc_node->content);
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
	//wait_child(data);
}
