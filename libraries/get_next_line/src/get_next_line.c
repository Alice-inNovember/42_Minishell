/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:39:24 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*get_next_line(int fd)
{
	static t_glist	*list;
	t_glist			*current_node;
	char			*line;
	int				total_len;

	line = NULL;
	total_len = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	current_node = set_current_node(&list, fd);
	if (current_node == NULL)
		return (NULL);
	if (read(current_node->fd, NULL, 0) < 0)
		return (free_all(&list, current_node, line, FREE_WITHOUT_LINE));
	if (current_node->printed_buf_len != current_node->buf_len)
	{
		line = str_join_from_remain(current_node, &total_len);
		if (line == NULL)
			return (free_all(&list, current_node, line, FREE_WITH_LINE));
		if (line[total_len - 1] == '\n')
			return (add_nul(&list, current_node, line, total_len));
	}
	return (make_line(&list, current_node, line, &total_len));
}

char	*str_join_from_remain(t_glist *node, int *total_len)
{
	char	*joined_line;
	int		i;

	i = 0;
	joined_line = allocate_memory(node, node->printed_buf_len, *total_len);
	if (joined_line == NULL)
		return (NULL);
	while (node->printed_buf_len + i < node->buf_len)
	{
		joined_line[i] = node->buf[node->printed_buf_len + i];
		if (node->buf[node->printed_buf_len + i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	node->printed_buf_len += i;
	*total_len += i;
	return (joined_line);
}

char	*make_line(t_glist **list, t_glist *node, char *line, int *total_len)
{
	while (1)
	{
		node->buf_len = read(node->fd, node->buf, BUFFER_SIZE);
		if (node->buf_len < 0 || (node->buf_len == 0 && *total_len == 0))
			return (free_all(list, node, line, FREE_WITH_LINE));
		if (node->buf_len == 0)
		{
			line = add_nul(list, node, line, *total_len);
			if (line == NULL)
				return (NULL);
			free_all(list, node, line, FREE_WITHOUT_LINE);
			return (line);
		}
		line = str_join(node, line, total_len);
		if (line == NULL)
			return (free_all(list, node, line, FREE_WITH_LINE));
		if (node->buf_len != BUFFER_SIZE || line[*total_len - 1] == '\n')
			return (add_nul(list, node, line, *total_len));
	}
}

char	*str_join(t_glist *node, char *line, int *total_len)
{
	char	*joined_line;
	int		i;

	i = 0;
	joined_line = allocate_memory(node, 0, *total_len);
	if (joined_line == NULL)
		return (NULL);
	str_copy(joined_line, line, *total_len, JUST_COPY);
	while (i < node->buf_len)
	{
		joined_line[*total_len + i] = node->buf[i];
		if (node->buf[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	node->printed_buf_len = i;
	*total_len += i;
	return (joined_line);
}

char	*add_nul(t_glist **list, t_glist *node, char *line, int total_len)
{
	char	*nul_added_line;

	nul_added_line = (char *)malloc(sizeof(char) * (total_len + 1));
	if (nul_added_line == NULL)
		return (free_all(list, node, line, FREE_WITH_LINE));
	str_copy(nul_added_line, line, total_len, COPY_AND_ADD_NUL);
	return (nul_added_line);
}
