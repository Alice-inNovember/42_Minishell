/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:53:25 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/lexer.h"

void	check_expand(t_state *state, t_asset *asset)
{
	const char	next_input = asset->line[asset->index + 1];
	char		*env_start;

	env_start = &asset->line[asset->index + 1];
	if (is_limiter(asset->token_list))
		*state = ADD_BUF_WORD;
	else
	{
		if (next_input == '?')
			*state = QUESTION_MARK_EXPAND;
		else if (get_env_length(env_start) > 0)
			*state = EXPAND;
		else
			*state = ADD_BUF_WORD;
	}
}
