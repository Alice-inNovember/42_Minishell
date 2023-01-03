/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_token_list_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:01:31 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/03 16:47:54 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer.h"

void	del_buffer(void **content)
{
	ft_free(content);
}

char	*make_buf(char input)
{
	char	*buf;

	buf = (char *)ft_calloc(1, sizeof(char));
	*buf = input;
	return (buf);
}

char	*make_value(t_list *buf_list)
{
	t_node	*cur_node;
	char	*value;
	char	*buf;
	int		i;

	value = (char *)ft_calloc(list_size(buf_list), sizeof(char));
	cur_node = list_peek_first_node(buf_list);
	i = 0;
	while (cur_node->next != NULL)
	{
		buf = cur_node->content;
		value[i++] = *buf;
		cur_node = cur_node->next;
	}
	return (value);
}

void	make_token(t_list *token_list, t_list *buf_list, t_type type)
{
	t_token	*token;
	char	*value;

	token = (t_token *)ft_calloc(1, sizeof(t_token));
	value = make_value(buf_list);
	token->type = type;
	token->value = value;
	list_append(token_list, new_node(token));
	list_clear(buf_list, del_buffer);
	list_init(buf_list);
}
