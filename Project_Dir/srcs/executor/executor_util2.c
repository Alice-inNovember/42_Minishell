/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_util2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:43:41 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/06 17:17:59 by jincpark         ###   ########.fr       */
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

int	open_redirect(t_redir *redir)
{
	int	fd;

	if (redir->type == T_GREAT || redir->type == T_DGREAT)
	{
		if (redir->type == T_GREAT)
			fd = open(redir->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (redir->type == T_DGREAT)
			fd = open(redir->filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
			(perror("Could not open file"), exit(EXIT_FAILURE));
		(dup2(fd, STDOUT_FILENO), close(fd));
	}
	else
	{
		fd = open(redir->filename, O_RDONLY, 0644);
		if (fd == -1)
			(perror("Could not open file"), exit(EXIT_FAILURE));
		(dup2(fd, STDIN_FILENO), close(fd));
	}
	return (fd);
}

void	do_redirect(t_proc_data *proc_data)
{
	t_node	*node;

	node = list_peek_first_node(&proc_data->redir_list);
	while (node->next != NULL)
	{
		open_redirect(((t_redir *)node->content));
		node = node->next;
	}
}

int	is_last_cmd(t_data *data, t_proc_data *proc_data)
{
	t_node	*node;

	node = list_peek_last_node(&data->proc_data_list);
	return (node->content == proc_data);
}
