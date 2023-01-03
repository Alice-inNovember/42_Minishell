/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_dless.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:52:54 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/03 16:53:20 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/lexer.h"

void	making_dless(t_state *state, t_data *data, t_list *buf_list, int *idx)
{
	const char	input = data->line[*idx];
	char		*buf;

	buf = make_buf(input);
	list_append(buf_list, new_node(buf));
	make_token(&data->token_list, buf_list, T_DLESS);
	*state = BRANCH;
	(*idx)++;
}
