/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_dquote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:13:39 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/08 22:57:52 by minseok2         ###   ########.fr       */
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
