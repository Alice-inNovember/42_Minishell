/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_expand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:13:52 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/08 21:32:03 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/lexer.h"

void	branch_expand(t_state *state, t_asset *asset)
{
	const char	input = asset->line[asset->index];

	if (ft_strchr(" \b\t\n\v\f\r", input))
		*state = SKIP_SPACE_IN_EXPAND;
	else if (input == '\\')
	{
		asset->index++;
		*state = EXPAND_END;
	}
	else
		*state = ADD_BUF_IN_EXPAND;
}
