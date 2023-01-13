/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_expand_dquote.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:15:16 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../includes/lexer.h"

void	check_expand_dquote(t_state *state, t_asset *asset)
{
	const char	next_input = asset->line[asset->index + 1];
	char		*env_start;

	env_start = &asset->line[asset->index + 1];
	if (!is_limiter(asset->token_list))
	{
		if (next_input == '?')
			*state = QUESTION_MARK_EXPAND_DQUOTE;
		else if (get_env_length(env_start) > 0)
			*state = EXPAND_DQUOTE;
		else
			*state = ADD_BUF_IN_DQUOTE;
	}
}
