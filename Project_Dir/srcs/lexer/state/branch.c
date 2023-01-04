/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:13:49 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/04 09:43:03 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/lexer.h"

void	branch(t_state *state, t_data *data, t_list *buf_list, int *idx)
{
	const char	input = data->line[*idx];

	if (input == ' ')
		(*idx)++;
	else if (input == '\0')
		*state = CLEAR;
	else if (input == '$' && \
				is_expansion(data->line, *idx, &data->token_list))
		*state = EXPAND;
	else if (input == '|')
		*state = MAKING_PIPE;
	else if (input == '<')
		*state = MAKING_LESS;
	else if (input == '>')
		*state = MAKING_GREAT;
	else if (input == '\'')
		*state = QUOTE_BRANCH;
	else if (input == '\"')
		*state = DQUOTE_BRANCH;
	else
		*state = MAKING_WORD;
	(t_unused)buf_list;
}
