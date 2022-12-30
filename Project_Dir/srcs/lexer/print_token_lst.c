/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:45:32 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/30 10:02:41 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/lexer1.h"

void	print_token_type(t_type type)
{
	if (type == T_WORD)
		printf("type = WORD\n");
	else if (type == T_PIPE)
		printf("type = PIPE\n");
	else if (type == T_LESS)
		printf("type = LESS\n");
	else if (type == T_GREAT)
		printf("type = GREAT\n");
	else if (type == T_DLESS)
		printf("type = DLESS\n");
	else if (type == T_DGREAT)
		printf("type = DGREAT\n");
}

void	print_token_value(char *value)
{
	if (value != NULL)
		printf("value = %s\n", value);
	else
		printf("value is unset\n");
}

void	print_token_lst(t_list *token_lst)
{
	t_node	*cur_node;
	t_token	*token;

	cur_node = lst_peek_first_node(token_lst);
	while (cur_node->next != NULL)
	{
		token = cur_node->content;
		print_token_type(token->type);
		print_token_value(token->value);
		cur_node = cur_node->next;
	}
}
