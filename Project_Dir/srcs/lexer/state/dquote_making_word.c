/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dquote_making_word.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:26:23 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/03 20:10:45 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/lexer.h"

void	dquote_making_word(t_state *state, \
									t_data *data, t_list *buf_list, int *idx)
{
	const char	input = data->line[*idx];
	char		*buf;

	buf = make_buf(input);
	list_append(buf_list, new_node(buf));
	*state = DQUOTE_BRANCH;
	(*idx)++;
}
