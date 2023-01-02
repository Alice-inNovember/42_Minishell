/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_token_list_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:43:28 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/02 21:07:28 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/lexer1.h"

void	free_pack(t_pack *pack)
{
	lst_clear(pack->token_lst, del_token);
	lst_clear(pack->envp_lst, NULL); //수정필요
	lst_clear(&pack->buffer_lst, del_buffer);
	ft_free((void **)&pack->line);
}

void	del_token(void **content)
{
	t_token	*token;

	token = *content;
	ft_free((void **)&token->value);
}

void	del_buffer(void **content)
{
	ft_free(content);
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
	lst_clear(buffer_lst, del_buffer);
	lst_init(buffer_lst);
}

char	*make_buffer(char character)
{
	char	*buffer;

	buffer = (char *)ft_calloc(1, sizeof(char));
	*buffer = character;
	return (buffer);
}

void	create_token(t_list *token_lst, t_list *buffer_lst, t_type type)
{
	t_token	*token;
	char	*value;

	token = (t_token *)ft_calloc(1, sizeof(t_token));
	value = (char *)ft_calloc(lst_size(buffer_lst) + 1, sizeof(char));
	copy_buffer(value, buffer_lst);
	token->value = value;
	token->type = type;
	lst_append(token_lst, new_node(token));
}
