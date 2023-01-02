/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:15:22 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/02 16:01:24 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/lexer1.h"

void	branch(t_status *status, t_pack *pack)
{
	const char	input = pack->line[pack->index];

	if (input == ' ')
		pack->index++;
	else if (input == '\0')
		*status = FINISH;
	else if (input == '$' && is_proper_env(&pack->line[pack->index]) && \
			!is_heredoc_limit_string(pack->token_lst))
		*status = EXPAND;
	else if (input == '|')
		*status = MAKING_PIPE;
	else if (input == '<')
		*status = MAKING_LESS;
	else if (input == '>')
		*status = MAKING_GREAT;
	else if (input == '\'')
		*status = QUOTE_OPEN;
	else if (input == '\"')
		*status = DQUOTE_OPEN;
	else
		*status = MAKING_WORD;
}
