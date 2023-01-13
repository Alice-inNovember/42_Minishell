/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dquote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:18:13 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/08 22:21:42 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../includes/lexer.h"

void	expand_dquote(t_state *state, t_asset *asset)
{
	char	*expanded_line;

	expanded_line = make_expanded_line(asset);
	free(asset->line);
	asset->line = expanded_line;
	*state = BRANCH_DQUOTE;
}
