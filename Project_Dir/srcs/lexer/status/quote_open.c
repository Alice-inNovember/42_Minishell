/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:19:27 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/29 16:42:58 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/lexer1.h"

void	quote_open(t_status *status, t_data *data, char **line, t_list *buffer_lst)
{
	if (**line == '\0')
		*status = ERROR;
	else if (**line == '\'')
	{
		*status = QUOTE_CLOSE;
		(*line)++;
	}
	else
		lst_append(buffer_lst, new_node(*line));
}
