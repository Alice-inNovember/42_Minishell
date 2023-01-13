/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_buf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:15:14 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/lexer.h"

char	*join_buf(t_list *buf_list)
{
	char	*value;
	char	*buf;
	t_node	*current_node;
	int		i;

	value = (char *)ft_calloc(list_size(buf_list) + 1, sizeof(char));
	current_node = list_peek_first_node(buf_list);
	i = 0;
	while (current_node->next != NULL)
	{
		buf = current_node->content;
		value[i++] = *buf;
		current_node = current_node->next;
	}
	return (value);
}
