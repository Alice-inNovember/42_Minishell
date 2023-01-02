/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:19:12 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/02 21:05:00 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/lexer1.h"

void	making_pipe(t_status *status, t_pack *pack)
{
	char	*buffer;

	buffer = make_buffer(pack->line[pack->index]);
	lst_append(&pack->buffer_lst, new_node(buffer));
	create_token(pack->token_lst, &pack->buffer_lst, T_PIPE);
	*status = BRANCH;
	pack->index++;
}
