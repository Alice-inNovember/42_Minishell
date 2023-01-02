/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:19:28 by junlee2           #+#    #+#             */
/*   Updated: 2022/12/30 20:47:42 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
 * 파이프 없음 && 빌트인 : no fork()
 */

pid_t	g_last_exit_status;

int	check_and_exec_single_builtin(t_data *data)
{
	t_node			*proc_node;
	char			*key;
	t_builtin_fp	bt_fp;

	proc_node = &data->proc_data_lst->head->next;
	key = (char *)proc_node->cmd_lst->head->next->content;
	bt_fp = builtin_find(&data->builtin_lst, key);
	if (data->proc_data_lst->size == 1 && bt_fp != NULL)
	{
		// redirection
		// do built_in
		return (1);
	}
	return (0);
}

void	wait_children(t_data *data)
{
	t_node	*pid_node;

	pid_node = lst_peek_first_node(&data->pid_lst);
	while (pid_node != NULL)
	{
		waitpid(*(pid_t *)pid_node->content, &g_last_pid, NULL);
		pid_node = pid_node->next;
	}
}

void	check_pipe_stat(int pipe_stat)
{
	if (pipe(fd) != 0)
	{
		wait_children(data);
		perror("minishell");
		exit(EXIT_FAILURE);
	}
}

pid_t	do_fork(t_data *data, t_node *proc_node)
{
	pid_t		*pid;
	int			fd[2];
	int			pipe_stat;
	static int	prev_read_end;

	pipe_stat = pipe(fd);
	check_pipe_stat(pipe_stat);
}

void	make_children(t_data *data)
{
	t_node	*proc_node;
	pid_t	*pid;

	proc_node = lst_peek_first_node(&data->proc_data_lst);
	while (proc_node != NULL)
	{
		pid = ft_calloc(1, sizeof(pid_t));
		*pid = do_fork(data, proc_node);
		lst_append(&data->pid_lst, (void *)pid);
		proc_node = proc_node->next;
	}
}

void	executor(t_data *data)
{
	if (check_and_exec_single_builtin(data))
		return ;
	make_children(data);
	wait_children(data);
}
