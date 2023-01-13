/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_buf_in_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:41:59 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/13 10:06:17 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/lexer.h"

void	add_buf_in_quote(t_state *state, t_asset *asset)
{
	const char	input = asset->line[asset->index];
	char		*buf;

	buf = make_buf(input);
	list_append(&asset->buf_list, new_node(buf));
	asset->index++;
	*state = BRANCH_QUOTE;
}
