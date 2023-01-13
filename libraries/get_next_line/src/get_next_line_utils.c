/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:56:25 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

t_glist	*set_current_node(t_glist **list, int fd)
{
	t_glist	*circulation_list;
	t_glist	*new_node;
	size_t	i;

	i = 0;
	circulation_list = *list;
	while (*list != NULL)
	{
		if (circulation_list->fd == fd)
			return (circulation_list);
		if (circulation_list->next == NULL)
			break ;
		circulation_list = circulation_list->next;
	}
	new_node = (t_glist *)malloc(sizeof(t_glist));
	if (new_node == NULL)
		return (NULL);
	while (i < sizeof(t_glist))
		((unsigned char *)new_node)[i++] = 0;
	new_node->fd = fd;
	if (*list == NULL)
		return (*list = new_node);
	else
		return (circulation_list->next = new_node);
}

char	*allocate_memory(t_glist *node, int buf_start_index, int total_len)
{
	char	*joined_line;
	int		attach_size;

	attach_size = 0;
	while (buf_start_index + attach_size < node->buf_len)
	{
		if (node->buf[buf_start_index + attach_size] == '\n')
		{
			attach_size++;
			break ;
		}
		attach_size++;
	}
	joined_line = (char *)malloc(sizeof(char) * (total_len + attach_size));
	if (joined_line == NULL)
		return (NULL);
	else
		return (joined_line);
}

void	str_copy(char *joined_line, char *line, int total_len, int option)
{
	int	i;

	i = 0;
	while (i < total_len)
	{
		joined_line[i] = line[i];
		i++;
	}
	if (option == COPY_AND_ADD_NUL)
		joined_line[i] = '\0';
	free(line);
	line = NULL;
}

char	*free_all(t_glist **list, t_glist *node, char *line, int option)
{
	t_glist	*circulation_list;

	if (option == FREE_WITH_LINE)
	{
		free(line);
		line = NULL;
	}
	if (*list == node)
	{
		*list = node->next;
		free(node);
		node = NULL;
		return (NULL);
	}
	circulation_list = *list;
	while (circulation_list->next)
	{
		if (circulation_list->next == node)
			break ;
		circulation_list = circulation_list->next;
	}
	circulation_list->next = node->next;
	free(node);
	node = NULL;
	return (NULL);
}
