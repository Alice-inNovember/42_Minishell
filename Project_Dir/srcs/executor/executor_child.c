/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:40:20 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/07 08:14:43 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include "../../includes/data.h"
#include "../../includes/envp.h"
#include "../../includes/builtin.h"
#include "../../includes/executor.h"

void	child_pip_redirect(t_proc_data *proc_data, int write_end, int read_end)
{
	t_node	*node;

	if (read_end != 0)
	{
		dup2(read_end, STDIN_FILENO);
		close(read_end);
	}
	if (write_end != STDOUT_FILENO)
	{
		dup2(write_end, STDOUT_FILENO);
		close(write_end);
	}
	do_redirect(proc_data);
}

void	execute_builtin(t_builtin_fp bt_fp, char **cmd_argv, t_list *envp_list)
{
	exit (bt_fp(cmd_argv, envp_list));
}

void	execute_execve(t_data *data, char **cmd_argv, char **cmd_envp)
{
	char	*cmd_path;
	char	*msg;

	cmd_path = get_cmd_path(data, cmd_argv);
	execve(cmd_path, cmd_argv, cmd_envp);
	msg = str3join("minishell: command not found: ", cmd_argv[0], "\n");
	ft_putstr_fd(msg, STDERR_FILENO);
	free(msg);
	exit(EXIT_FAILURE);
}

void	execute_child(t_data *data, t_proc_data *proc, int w_end, int r_end)
{
	t_builtin_fp	builtin_fp;
	char			**cmd_argv;
	char			**cmd_envp;

	child_pip_redirect(proc, w_end, r_end);
	cmd_argv = cmd_list2arr(&proc->cmd_list);
	cmd_envp = envp2arr(&data->envp_list);
	builtin_fp = builtin_find(&data->builtin_list, cmd_argv[0]);
	if (builtin_fp)
		execute_builtin(builtin_fp, cmd_argv, &data->envp_list);
	else
		execute_execve(data, cmd_argv, cmd_envp);
}
