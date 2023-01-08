/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_util2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:43:41 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/08 20:12:45 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/_types/_pid_t.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "../../includes/data.h"

void	pid_list_add(t_list *pidlist, pid_t pid)
{
	pid_t	*pidptr;

	pidptr = ft_malloc(sizeof(pid_t));
	*pidptr = pid;
	list_append(pidlist, new_node(pidptr));
}

int	open_redirect(t_redir *redir)
{
	int		fd;
	char	*err_msg;

	err_msg = ft_strjoin("minishell: ", redir->filename);
	if (redir->type == T_GREAT || redir->type == T_DGREAT)
	{
		if (redir->type == T_GREAT)
			fd = open(redir->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else
			fd = open(redir->filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
			(perror(err_msg), free(err_msg), exit(EXIT_FAILURE));
		(dup2(fd, STDOUT_FILENO), close(fd));
	}
	else
	{
		fd = open(redir->filename, O_RDONLY, 0644);
		if (fd == -1)
			(perror(err_msg), free(err_msg), exit(EXIT_FAILURE));
		(dup2(fd, STDIN_FILENO), close(fd));
	}
	free(err_msg);
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

int	is_first_cmd(t_data *data, t_proc_data *proc_data)
{
	t_node	*node;

	node = list_peek_first_node(&data->proc_data_list);
	return (node->content == proc_data);
}
