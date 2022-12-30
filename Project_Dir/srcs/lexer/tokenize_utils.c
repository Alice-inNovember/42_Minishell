/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:43:28 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/30 16:47:27 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/lexer1.h"

void	del_token(void **content)
{
	t_token	*token;

	token = *content;
	ft_free((void **)&token->value);
}

void	copy_buffer(char *value, t_list *buffer_lst)
{
	t_node	*cur_node;
	int		i;

	cur_node = lst_peek_first_node(buffer_lst);
	i = 0;
	while (cur_node->next != NULL)
	{
		value[i++] = *((char *)cur_node->content);
		cur_node = cur_node->next;
	}
	lst_clear(buffer_lst, NULL);
	lst_init(buffer_lst);
}

void	create_token(t_list *token_lst, t_list *buffer_lst, t_type type)
{
	t_token	*token;
	char	*value;

	token = (t_token *)ft_calloc(1, sizeof(t_token));
	if (type == T_WORD)
	{
		value = (char *)ft_calloc(lst_size(buffer_lst) + 1, sizeof(char));
		copy_buffer(value, buffer_lst);
	}
	else
		value = NULL;
	token->value = value;
	token->type = type;
	lst_append(token_lst, new_node(token));
}
