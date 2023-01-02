/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dquote_open.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:18:47 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/02 15:45:27 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/lexer1.h"

void	dquote_open(t_status *status, t_pack *pack)
{
	if (pack->line[pack->index + 1] == '\0')
		*status = DQUOTE_ERROR;
	else if (pack->line[pack->index + 1] == '$' && \
			is_proper_env(&pack->line[pack->index + 1]) && \
			!is_heredoc_limit_string(pack->token_lst))
		*status = DQUOTE_EXPAND;
	else if (pack->line[pack->index + 1] == '\"')
		*status = DQUOTE_CLOSE;
	else
		lst_append(&pack->buffer_lst, new_node(&pack->line[pack->index + 1]));
	pack->index++;
}
