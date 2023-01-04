/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:59:44 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/04 10:04:56 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

void	print_token_list(t_data *data)
{
	t_node	*cur_node;
	t_token	*token;

	if (data->syntax_err_flag != E_NONE)
		return ;
	cur_node = list_peek_first_node(&data->token_list);
	while (cur_node->next != NULL)
	{
		token = cur_node->content;
		print_token_type(token->type);
		print_token_value(token->value);
		cur_node = cur_node->next;
	}
}
