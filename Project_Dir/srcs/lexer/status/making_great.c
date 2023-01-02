/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_great.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:19:03 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/02 21:04:23 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/lexer1.h"

void	making_great(t_status *status, t_pack *pack)
{
	char	*buffer;

	buffer = make_buffer(pack->line[pack->index]);
	lst_append(&pack->buffer_lst, new_node(buffer));
	if (pack->line[pack->index + 1] == '>')
		*status = MAKING_DGREAT;
	else
	{
		create_token(pack->token_lst, &pack->buffer_lst, T_GREAT);
		*status = BRANCH;
	}
	pack->index++;
}
