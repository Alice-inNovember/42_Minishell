/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_making_literal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:37:39 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/29 16:39:43 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/lexer1.h"

void	quote_making_literal(t_status *status, t_data *data, char **line, t_list *buffer_lst)
{
	if (**line == '\0')
		*status = ERROR;
	else if (**line == '\'')
	{
		*status = QUOTE_CLOSE;
	}
}
