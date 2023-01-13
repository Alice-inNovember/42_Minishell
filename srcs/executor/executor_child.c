/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:40:20 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/13 20:01:19 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../includes/envp.h"
#include "../../includes/util.h"
#include "../../includes/builtin.h"
#include "../../includes/executor.h"
#include "../../includes/signal_handler.h"

void	pip_redirect(t_proc_data *proc_data, int write_end, int read_end)
{
	ft_dup2(read_end, STDIN_FILENO);
	close(read_end);
	ft_dup2(write_end, STDOUT_FILENO);
	close(write_end);
	if (do_redirect(proc_data))
		exit (EXIT_FAILURE);
}

void	fl_redirect(t_data *data, t_proc_data *proc, int pip[2][2], int *origin)
{
	if (is_first_cmd(data, proc))
		ft_dup2(origin[READ_END], pip[PREV][READ_END]);
	if (is_last_cmd(data, proc))
		ft_dup2(origin[WRITE_END], pip[NOW][WRITE_END]);
}

void	execute_builtin(t_builtin_fp bt_fp, char **cmd_argv, t_list *envp_list)
{
	exit (bt_fp(cmd_argv, envp_list));
}

void	execute_execve(t_data *data, char **cmd_argv, char **cmd_envp)
{
	struct stat	sb;
	char		*cmd_path;

	if (cmd_argv[0][0] == 0)
		(error_msg(cmd_argv[0], EN_CNOT_FIND), exit(EX_CNOT_FIND));
	cmd_path = get_cmd_path(data, cmd_argv);
	if (cmd_path == NULL)
		(error_msg(cmd_argv[0], EN_CNOT_FIND), exit(EX_CNOT_FIND));
	ft_stat(cmd_path, &sb);
	if ((sb.st_mode & S_IFMT) == S_IFDIR)
		(error_msg(cmd_argv[0], EN_IS_DIR), exit(EX_CNOT_EXEC));
	else if (access(cmd_path, X_OK) == -1)
		(error_msg(cmd_argv[0], EN_PER_DENIED), exit(EX_CNOT_EXEC));
	ft_execve(cmd_path, cmd_argv, cmd_envp);
}

void	execute_child(t_data *data, t_proc_data *proc, int pip[2][2], int *ofd)
{
	t_builtin_fp	builtin_fp;
	char			**cmd_argv;
	char			**cmd_envp;

	close(pip[NOW][READ_END]);
	fl_redirect(data, proc, pip, ofd);
	pip_redirect(proc, pip[NOW][WRITE_END], pip[PREV][READ_END]);
	if (list_size(&proc->cmd_list) == 0)
		exit(EXIT_SUCCESS);
	cmd_argv = cmd_list2arr(&proc->cmd_list);
	cmd_envp = envp2arr(&data->envp_list);
	builtin_fp = builtin_find(&data->builtin_list, cmd_argv[0]);
	if (builtin_fp)
		execute_builtin(builtin_fp, cmd_argv, &data->envp_list);
	else
		execute_execve(data, cmd_argv, cmd_envp);
}
