/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dquote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:18:13 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr       */
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
