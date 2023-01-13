/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_word_token_expand.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:24:45 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/lexer.h"

void	make_word_token_expand(t_state *state, t_asset *asset)
{
	const char	input = asset->line[asset->index];
	t_token		*token;

	if (list_size(&asset->buf_list) > 0 && ft_isspace(input))
	{
		token = (t_token *)ft_calloc(1, sizeof(t_token));
		token->type = T_WORD;
		token->value = join_buf(&asset->buf_list);
		list_clear(&asset->buf_list, free);
		list_init(&asset->buf_list);
		list_append(asset->token_list, new_node(token));
	}
	*state = BRANCH_EXPAND;
}
