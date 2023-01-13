/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:34:43 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/08 19:38:34 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/lexer.h"

void	branch_quote(t_state *state, t_asset *asset)
{
	const char	input = asset->line[asset->index];

	if (input == '\0')
		*state = OPEN_QUOTE_ERROR;
	else if (input == '\'')
		*state = CLOSE_QUOTE;
	else
		*state = ADD_BUF_IN_QUOTE;
}
