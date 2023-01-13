/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_great.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:24:34 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/13 10:06:06 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/lexer.h"

void	branch_great(t_state *state, t_asset *asset)
{
	const char	input = asset->line[asset->index];

	if (input == '>')
		*state = ADD_BUF_DGREAT;
	else
		*state = MAKE_GREAT_TOKEN;
}
