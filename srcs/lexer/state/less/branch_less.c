/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_less.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:20:15 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/13 10:05:57 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/lexer.h"

void	branch_less(t_state *state, t_asset *asset)
{
	const char	input = asset->line[asset->index];

	if (input == '<')
		*state = ADD_BUF_DLESS;
	else
		*state = MAKE_LESS_TOKEN;
}
