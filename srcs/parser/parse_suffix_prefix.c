/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_suffix_prefix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:37:49 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/13 13:07:51 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	parse_cmd_prefix(t_data *data, t_proc_data *procdata, t_list *tokenlist)
{
	t_node	*first;
	t_node	*last;

	if (is_return_case(data, tokenlist, E_NONE))
		return ;
	first = list_peek_first_node(tokenlist);
	last = list_peek_last_node(tokenlist);
	parse_cmd_prefix(data, procdata, sub_token_list(first, last->prev->prev));
	parse_redirect(data, procdata, sub_token_list(last->prev, last));
	clear_and_free_token_list(tokenlist);
}

void	parse_cmd_suffix(t_data *data, t_proc_data *procdata, t_list *tokenlist)
{
	t_node	*first;
	t_node	*last;

	if (is_return_case(data, tokenlist, E_NONE))
		return ;
	first = list_peek_first_node(tokenlist);
	last = list_peek_last_node(tokenlist);
	if (is_redir_form(data, last->prev))
	{
		parse_cmd_suffix(data, procdata, \
		sub_token_list(first, last->prev->prev));
		parse_redirect(data, procdata, sub_token_list(last->prev, last));
		clear_and_free_token_list(tokenlist);
	}
	else
	{
		parse_cmd_suffix(data, procdata, sub_token_list(first, last->prev));
		if (is_redir(((t_token *)last->content)->type))
			data->syntax_err_flag = E_NEAR_NEWLINE;
		parse_cmd_word(data, procdata, sub_token_list(last, last));
		clear_and_free_token_list(tokenlist);
	}
}
