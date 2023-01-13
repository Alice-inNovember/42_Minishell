/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_expand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:13:52 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/lexer.h"

void	branch_expand(t_state *state, t_asset *asset)
{
	const char	input = asset->line[asset->index];

	if (ft_isspace(input))
		*state = SKIP_SPACE_IN_EXPAND;
	else if (input == '\\')
	{
		asset->index++;
		*state = EXPAND_END;
	}
	else
		*state = ADD_BUF_IN_EXPAND;
}
