/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:19:19 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/02 21:08:55 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/lexer1.h"

void	making_word(t_status *status, t_pack *pack)
{
	char	*buffer;

	if (pack->line[pack->index] == '\0')
	{
		create_token(pack->token_lst, &pack->buffer_lst, T_WORD);
		*status = FINISH;
		return ;
	}
	buffer = make_buffer(pack->line[pack->index]);
	lst_append(&pack->buffer_lst, new_node(buffer));
	if (pack->line[pack->index + 1] == '\0' || \
			ft_strchr(" |<>", pack->line[pack->index + 1]))
		create_token(pack->token_lst, &pack->buffer_lst, T_WORD);
	*status = BRANCH;
	pack->index++;
}
