/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_util2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:43:41 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/06 13:02:26 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <sys/_types/_pid_t.h>
#include <unistd.h>

void	pid_list_add(t_list *pidlist, pid_t pid)
{
	pid_t	*pidptr;

	pidptr = ft_malloc(sizeof(pid_t));
	*pidptr = pid;
	list_append(pidlist, new_node(pidptr));
}

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

void	single_bt_redirect(int *origin_io, t_proc_data *proc_data)
{
	t_node	*node;

	origin_io[READ_END] = dup(STDIN_FILENO);
	origin_io[WRITE_END] = dup(STDOUT_FILENO);
	node = list_peek_first_node(&proc_data->redir_list);
	while (node->next != NULL)
	{
		open_redirect(((t_redir *)node->content));
		node = node->next;
	}
}
