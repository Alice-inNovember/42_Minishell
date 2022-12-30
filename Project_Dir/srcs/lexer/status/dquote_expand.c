/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dquote_expand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 09:07:12 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/30 11:12:40 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/lexer1.h"

void	dquote_expand(t_status *status, t_data *data, char **line, t_list *buffer_lst)
{
	const t_token	*last_token = lst_peek_last_content(&data->token_lst);

	if (last_token->type == T_DLESS)
	{
		*status = DQUOTE_OPEN;
		return ;
	}
}
