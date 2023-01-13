/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_buf_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:04:10 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/13 10:06:24 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/lexer.h"

void	add_buf_pipe(t_state *state, t_asset *asset)
{
	const char	input = asset->line[asset->index];
	char		*buf;

	buf = make_buf(input);
	list_append(&asset->buf_list, new_node(buf));
	asset->index++;
	*state = MAKE_PIPE_TOKEN;
}
