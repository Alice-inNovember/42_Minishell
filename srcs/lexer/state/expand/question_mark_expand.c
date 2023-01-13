/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   question_mark_expand.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:14:36 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/lexer.h"

void	question_mark_expand(t_state *state, t_asset *asset)
{
	char	*question_mark_expanded_line;

	question_mark_expanded_line = make_question_mark_expanded_line(asset);
	free(asset->line);
	asset->line = question_mark_expanded_line;
	*state = MAKE_WORD_TOKEN_EXPAND;
}
