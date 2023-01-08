/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   question_mark_expand_dquote.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:17:11 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/08 22:25:02 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../includes/lexer.h"

void	question_mark_expand_dquote(t_state *state, t_asset *asset)
{
	char	*question_mark_expanded_line;

	question_mark_expanded_line = make_question_mark_expanded_line(asset);
	free(asset->line);
	asset->line = question_mark_expanded_line;
	*state = BRANCH_DQUOTE;
}
