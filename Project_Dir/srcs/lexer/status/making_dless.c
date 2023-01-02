/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_dless.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:18:59 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/02 14:54:13 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/lexer1.h"

void	making_dless(t_status *status, t_pack *pack)
{
	lst_append(&pack->buffer_lst, new_node(&pack->line[pack->index]));
	create_token(pack->token_lst, &pack->buffer_lst, T_DLESS);
	*status = BRANCH;
	pack->index++;
}
