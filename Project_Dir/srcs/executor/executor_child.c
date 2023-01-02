/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:40:20 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/02 15:45:16 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>

int	open_redirect(t_redir *redir_data)
{
	int	fd;

	if (redir_data->type == T_GREAT || redir_data->type == T_DGREAT)
	{
		if (redir_data->type == T_GREAT)
			fd = open(redir_data->fname, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (redir_data->type == T_DGREAT)
			fd = open(redir_data->fname, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
			(perror("Could not open file"), exit(EXIT_FAILURE));
		(dup2(fd, STDOUT_FILENO), close(fd));
	}
	else
	{
		fd = open(redir_data->fname, O_RDONLY, 0644);
		if (fd == -1)
			(perror("Could not open file"), exit(EXIT_FAILURE));
		(dup2(fd, STDIN_FILENO), close(fd));
	}
	return (fd);
}

void	child_redirect(t_proc_data *proc_data, int *pip, int read_end)
{
	t_node	*node;

	if (read_end != -1)
	{
		dup2(read_end, STDIN_FILENO);
		close(read_end);
	}
	dup2(pip[1], STDOUT_FILENO);
	close(pip[1]);
	if (lst_size(&proc_data->redir_lst))
		return ;
	node = lst_peek_first_node(&proc_data->redir_lst);
	while (node->next != NULL)
	{
		open_redirect(((t_redir *)node->content));
		node = node->next;
	}
}

void	execute_child(t_data *data, t_proc_data *proc, int *pip, int read_end)
{
	t_builtin_fp	builtin_fp;
	char			**cmd_argv;
	char			**cmd_envp;

	child_redirect(proc, pip, read_end);
	cmd_argv = cmd_list2arr(&proc->cmd_lst);
	cmd_envp = envp2arr(&data->envp_lst);
	builtin_fp = builtin_find(&data->builtin_lst, cmd_argv[0]);
	if (builtin_fp)
		execute_builtin();
	else
		execute_execve();
}
