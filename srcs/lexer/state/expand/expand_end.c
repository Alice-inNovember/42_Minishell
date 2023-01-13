/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:28:14 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/12 17:38:36 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/lexer.h"

void	expand_end(t_state *state, t_asset *asset)
{
	const char	input = asset->line[asset->index];
	t_token		*token;

	if (list_size(&asset->buf_list) > 0 && \
			(input == '\0' || ft_isspace(input) || ft_strchr("|<>", input)))
	{
		token = (t_token *)ft_calloc(1, sizeof(t_token));
		token->type = T_WORD;
		token->value = join_buf(&asset->buf_list);
		list_clear(&asset->buf_list, free);
		list_init(&asset->buf_list);
		list_append(asset->token_list, new_node(token));
	}
	*state = BRANCH;
}
