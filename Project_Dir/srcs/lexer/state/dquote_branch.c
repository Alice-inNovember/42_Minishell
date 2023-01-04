/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dquote_branch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:46:14 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/04 09:57:31 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/lexer.h"

void	dquote_branch(t_state *state, t_data *data, t_list *buf_list, int *idx)
{
	const char	next_input = data->line[*idx + 1];

	if (next_input == '\0')
	{
		data->syntax_err_flag = E_SINGLE_DQUOTE;
		*state = CLEAR;
		return ;
	}
	else if (next_input == '$' && \
				is_expansion(data->line, *idx + 1, &data->token_list))
	{
		*state = DQUOTE_EXPAND;
		return ;
	}
	else if (next_input == '\"')
		*state = DQUOTE_CLOSE;
	else
		*state = DQUOTE_MAKING_WORD;
	(*idx)++;
	(t_unused)buf_list;
}
