/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:09:23 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/08 21:44:15 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/lexer.h"

void	expand(t_state *state, t_asset *asset)
{
	char	*expanded_line;

	expanded_line = make_expanded_line(asset);
	free(asset->line);
	asset->line = expanded_line;
	*state = MAKE_WORD_TOKEN_EXPAND;
}
