/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:19:28 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/11 21:54:13 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"
#include "../../includes/builtin.h"
#include "../../includes/signal_handler.h"

extern int	g_exit_status;

int	check_single_builtin(t_data *data, t_list *envp_list)
{
	t_proc_data		*proc_data;
	t_builtin_fp	bt_fp;
	char			**cmd_argv;
	int				origin_io[2];

	bt_fp = NULL;
	proc_data = list_peek_first_content(&data->proc_data_list);
	cmd_argv = cmd_list2arr(&proc_data->cmd_list);
	if (cmd_argv[0] != NULL)
		bt_fp = builtin_find(&data->builtin_list, cmd_argv[0]);
	if (list_size(&data->proc_data_list) == 1 && bt_fp != NULL)
	{
		origin_io[READ_END] = dup(STDIN_FILENO);
		origin_io[WRITE_END] = dup(STDOUT_FILENO);
		if (do_redirect(proc_data))
			g_exit_status = 1;
		else
			g_exit_status = bt_fp(cmd_argv, envp_list);
		(dup2(origin_io[READ_END], 0), close(origin_io[READ_END]));
		(dup2(origin_io[WRITE_END], 1), close(origin_io[WRITE_END]));
		free(cmd_argv);
		return (1);
	}
	free(cmd_argv);
	return (0);
}

int	check_single_redirect(t_data *data)
{
	t_proc_data		*proc_data;
	char			**cmd_argv;
	int				origin_io[2];

	proc_data = list_peek_first_content(&data->proc_data_list);
	cmd_argv = cmd_list2arr(&proc_data->cmd_list);
	if (list_size(&data->proc_data_list) == 1)
	{
		if (list_size(&proc_data->cmd_list) == 0)
		{
			origin_io[READ_END] = dup(STDIN_FILENO);
			origin_io[WRITE_END] = dup(STDOUT_FILENO);
			if (do_redirect(proc_data))
				g_exit_status = 1;
			(dup2(origin_io[READ_END], 0), close(origin_io[READ_END]));
			(dup2(origin_io[WRITE_END], 1), close(origin_io[WRITE_END]));
			free(cmd_argv);
			return (1);
		}
	}
	free(cmd_argv);
	return (0);
}

void	wait_child(t_data *data)
{
	t_node	*node;
	int		status;
	int		status_tmp;

	status_tmp = 0;
	node = list_peek_first_node(&data->pid_list);
	while (node->next != NULL)
	{
		waitpid(*((pid_t *)node->content), &status, 0);
		status_tmp = status;
		if (wifsignaled(status))
			status = EX_BY_SIGNAL + wtermsig(status);
		else
			status = wexitstatus(status);
		g_exit_status = status;
		node = node->next;
	}
	if (wifsignaled(status_tmp))
	{
		if (status_tmp == SIGQUIT)
			ft_putendl_fd("Quit: 3", STDOUT_FILENO);
		else
			ft_putendl_fd("", STDOUT_FILENO);
	}
}
// SIGINT 종료 시 2 반환됨

void	make_child(t_data *data)
{
	t_node	*proc_node;
	pid_t	pid;
	int		pip[2][2];
	int		origin[2];

	origin[READ_END] = dup(STDIN_FILENO);
	origin[WRITE_END] = dup(STDOUT_FILENO);
	(pipe(pip[PREV]), close(pip[PREV][WRITE_END]));
	proc_node = list_peek_first_node(&data->proc_data_list);
	while (proc_node->next != NULL)
	{
		pipe(pip[NOW]);
		pid = fork();
		reset_signal(pid, 0);
		if (pid == 0)
			execute_child(data, proc_node->content, pip, origin);
		pid_list_add(&data->pid_list, pid);
		close(pip[PREV][READ_END]);
		close(pip[NOW][WRITE_END]);
		pip[PREV][READ_END] = pip[NOW][READ_END];
		proc_node = proc_node->next;
	}
	close(pip[NOW][READ_END]);
	close(origin[READ_END]);
	close(origin[WRITE_END]);
}

void	executor(t_data *data)
{
	if (data->syntax_err_flag != E_NONE || data->token_list.size == 0)
		return ;
	if (check_single_builtin(data, &data->envp_list))
		return ;
	if (check_single_redirect(data))
		return ;
	make_child(data);
	wait_child(data);
}
