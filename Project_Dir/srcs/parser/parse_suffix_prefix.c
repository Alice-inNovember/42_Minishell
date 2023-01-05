/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_suffix_prefix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:25:02 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/05 17:05:05 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	parse_cmd_prefix(t_data *data, t_proc_data *proc_data, t_list *token_list)
{
	t_node	*first;
	t_node	*last;

	if (is_return_case(data, token_list, E_NONE))
		return ;
	first = list_peek_first_node(token_list);
	last = list_peek_last_node(token_list);
	parse_cmd_prefix(data, proc_data, sub_token_list(first, last->prev->prev));
	parse_io_redirect(data, proc_data, sub_token_list(last->prev, last));
	clear_and_free_token_list(token_list);
}

void	parse_cmd_suffix(t_data *data, t_proc_data *proc_data, t_list *token_list)
{
	t_node	*first;
	t_node	*last;

	if (is_return_case(data, token_list, E_NONE))
		return ;
	first = list_peek_first_node(token_list);
	last = list_peek_last_node(token_list);
	if (is_redir_form(data, last->prev))
	{
		parse_cmd_suffix(data, proc_data, sub_token_list(first, last->prev->prev));
		parse_io_redirect(data, proc_data, sub_token_list(last->prev, last));
		clear_and_free_token_list(token_list);
		
	}
	else
	{
		parse_cmd_suffix(data, proc_data, sub_token_list(first, last->prev));
		if (is_redir(((t_token *)last->content)->type))
			data->syntax_err_flag = E_NEAR_NEWLINE;
		parse_cmd_word(data, proc_data, sub_token_list(last, last));
		clear_and_free_token_list(token_list);
	}
}
