/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dquote_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:18:42 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/30 09:42:05 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/lexer1.h"

void	dquote_close(t_status *status, t_data *data, char **line, t_list *buffer_lst)
{
	(*line)++;
	if (**line != '\'' || **line != '\"')
		create_token(&data->token_lst, buffer_lst, T_WORD);
	*status = BRANCH;
}
