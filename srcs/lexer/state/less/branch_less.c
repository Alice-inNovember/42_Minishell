/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_less.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:20:15 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/08 19:21:49 by minseok2         ###   ########.fr       */
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
