/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_great.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:53:32 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/03 16:53:56 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/lexer.h"

void	making_great(t_state *state, t_data *data, t_list *buf_list, int *idx)
{
	const char	input = data->line[*idx];
	const char	next_input = data->line[*idx + 1];
	char		*buf;

	buf = make_buf(input);
	list_append(buf_list, new_node(buf));
	if (next_input == '>')
		*state = MAKING_DGREAT;
	else
	{
		make_token(&data->token_list, buf_list, T_GREAT);
		*state = BRANCH;
	}
	(*idx)++;
}
