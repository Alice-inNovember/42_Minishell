/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_buf_in_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:41:59 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr       */
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
