/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:55:52 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/08 22:44:34 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/lexer.h"

void	branch(t_state *state, t_asset *asset)
{
	const char	input = asset->line[asset->index];

	if (input == '\0')
		*state = CLEAR;
	else if (ft_strchr(" \b\t\n\v\f\r", input))
		*state = SKIP_SPACE;
	else if (input == '$')
		*state = CHECK_EXPAND;
	else if (input == '|')
		*state = ADD_BUF_PIPE;
	else if (input == '<')
		*state = ADD_BUF_LESS;
	else if (input == '>')
		*state = ADD_BUF_GREAT;
	else if (input == '\'')
		*state = OPEN_QUOTE;
	else if (input == '\"')
		*state = OPEN_DQUOTE;
	else
		*state = ADD_BUF_WORD;
}
