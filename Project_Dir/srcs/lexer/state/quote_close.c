/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:33:38 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/03 19:45:02 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/lexer.h"

void	quote_close(t_state *state, t_data *data, t_list *buf_list, int *idx)
{
	const char	next_input = data->line[*idx + 1];

	if (next_input == '\0' || next_input == ' ')
		make_token(&data->token_list, buf_list, T_WORD);
	*state = BRANCH;
	(*idx)++;
}
