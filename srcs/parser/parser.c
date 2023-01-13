/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:45:08 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/13 10:00:23 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	parse_simple_cmd(t_data *data, t_list *token_list)
{
	t_node		*first;
	t_node		*cmd_node;
	t_node		*last;
	t_proc_data	*proc_data;

	if (is_return_case(data, token_list, E_NEAR_PIPE))
		return ;
	proc_data = new_proc_data();
	list_append(&data->proc_data_list, new_node((void *)proc_data));
	first = list_peek_first_node(token_list);
	cmd_node = get_cmd_node(data, token_list);
	last = list_peek_last_node(token_list);
	parse_cmd_prefix(data, proc_data, sub_token_list(first, cmd_node->prev));
	parse_cmd_word(data, proc_data, sub_token_list(cmd_node, cmd_node));
	parse_cmd_suffix(data, proc_data, sub_token_list(cmd_node->next, last));
	clear_and_free_token_list(token_list);
}

void	parse_expression(t_data *data, t_list *token_list)
{
	t_node	*first;
	t_node	*last;
	t_node	*curr;

	if (is_return_case(data, token_list, E_NEAR_PIPE))
		return ;
	first = list_peek_first_node(token_list);
	last = list_peek_last_node(token_list);
	curr = last;
	while (curr->prev != NULL)
	{
		if ((get_token(curr))->type == T_PIPE)
		{
			if (get_token(curr->prev) && \
			is_redir((get_token(curr->prev))->type))
				data->syntax_err_flag = E_NEAR_PIPE;
			parse_expression(data, sub_token_list(first, curr->prev));
			parse_simple_cmd(data, sub_token_list(curr->next, last));
			clear_and_free_token_list(token_list);
			return ;
		}
		curr = curr->prev;
	}
	parse_simple_cmd(data, sub_token_list(first, last));
	clear_and_free_token_list(token_list);
}

void	parser(t_data *data)
{
	t_list	*token_list_cp;
	t_node	*first_node;
	t_node	*last_node;

	if (data->syntax_err_flag != E_NONE || data->token_list.size == 0)
		return ;
	first_node = list_peek_first_node(&data->token_list);
	last_node = list_peek_last_node(&data->token_list);
	token_list_cp = sub_token_list(first_node, last_node);
	parse_expression(data, token_list_cp);
}
