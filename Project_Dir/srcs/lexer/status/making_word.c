/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:19:19 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/02 15:59:20 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/lexer1.h"

void	making_word(t_status *status, t_pack *pack)
{
	if (pack->line[pack->index] == '\0')
	{
		create_token(pack->token_lst, &pack->buffer_lst, T_WORD);
		*status = BRANCH;
		return ;
	}
	lst_append(&pack->buffer_lst, new_node(&pack->line[pack->index]));
	if (ft_strchr(" \0|<>", pack->line[pack->index + 1]))
		create_token(pack->token_lst, &pack->buffer_lst, T_WORD);
	*status = BRANCH;
	pack->index++;
}
