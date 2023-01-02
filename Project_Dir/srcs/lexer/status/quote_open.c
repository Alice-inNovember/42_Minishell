/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:19:27 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/02 14:59:23 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/lexer1.h"

void	quote_open(t_status *status, t_pack *pack)
{
	if (pack->line[pack->index + 1] == '\0')
		*status = QUOTE_ERROR;
	else if (pack->line[pack->index + 1] == '\'')
		*status = QUOTE_CLOSE;
	else
		lst_append(&pack->buffer_lst, new_node(&pack->line[pack->index + 1]));
	pack->index++;
}
