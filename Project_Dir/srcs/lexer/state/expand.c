/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:50:27 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/05 09:23:56 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/lexer.h"

void	expand(t_state *state, t_data *data, t_list *buf_list, int *idx)
{
	char	*expanded_line;

	expanded_line = make_expanded_line(data, *idx);
	free(data->line);
	data->line = expanded_line;
	if (data->line[*idx] == '\0')
		make_token(&data->token_list, buf_list, T_WORD);
	*state = BRANCH;
	(t_unused)buf_list;
}
