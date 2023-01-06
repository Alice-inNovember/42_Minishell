/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_util1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:43:41 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/06 17:17:57 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stddef.h>
#include <stdlib.h>
#include <sys/unistd.h>
#include <unistd.h>

char	**cmd_list2arr(t_list *cmd_list)
{
	t_node	*node;
	size_t	i;
	size_t	cmdlen;
	char	**cmdarr;

	node = list_peek_first_node(cmd_list);
	cmdlen = list_size(cmd_list);
	cmdarr = (char **)ft_malloc(sizeof(char *) * (cmdlen + 1));
	i = 0;
	while (i < cmdlen)
	{
		cmdarr[i] = node->content;
		node = node->next;
		i++;
	}
	cmdarr[i] = NULL;
	return (cmdarr);
}

char	**get_path(t_data *data)
{
	char	*path;
	char	**returnpath;

	path = envp_find(&data->envp_list, "PATH");
	returnpath = ft_split(path, ':');
	return (returnpath);
}

char	*get_cmd_path(t_data *data, char **cmd_argv)
{
	char	**path;
	char	*cmdpath;
	size_t	i;

	path = get_path(data);
	if (ft_strchr(cmd_argv[0], '/'))
		if (access(cmd_argv[0], F_OK | X_OK) == 0)
			return (cmd_argv[0]);
	i = 0;
	while (path[i])
	{
		cmdpath = str3join(path[i], "/", cmd_argv[0]);
		if (access(cmdpath, F_OK | X_OK) == 0)
			return (cmdpath);
		free(cmdpath);
		i++;
	}
	ft_free_vector(path);
	return (NULL);
}

void	cmd_argv_free(char **cmd_argv)
{
	free(cmd_argv);
}

int	wexitstatus(int status)
{
	int	exit_status;

	exit_status = ((unsigned)status >> 8) & 0xff;
	return (exit_status);
}
