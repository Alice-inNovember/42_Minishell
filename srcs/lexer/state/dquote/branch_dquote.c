/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_dquote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:13:39 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/lexer.h"

void	branch_dquote(t_state *state, t_asset *asset)
{
	const char	input = asset->line[asset->index];

	if (input == '\\')
		*state = SKIP_BACKSLASH_IN_DQUOTE;
	else if (input == '\0')
		*state = OPEN_DQUOTE_ERROR;
	else if (input == '$')
		*state = CHECK_EXPAND_DQUOTE;
	else if (input == '\"')
		*state = CLOSE_DQUOTE;
	else
		*state = ADD_BUF_IN_DQUOTE;
}
