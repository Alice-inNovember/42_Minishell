/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_less.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:19:08 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/02 14:53:48 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/lexer1.h"

void	making_less(t_status *status, t_pack *pack)
{
	lst_append(&pack->buffer_lst, new_node(&pack->line[pack->index]));
	if (pack->line[pack->index + 1] == '<')
		*status = MAKING_DLESS;
	else
	{
		create_token(pack->token_lst, &pack->buffer_lst, T_LESS);
		*status = BRANCH;
	}
	pack->index++;
}
