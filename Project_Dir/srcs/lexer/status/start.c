/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:15:22 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/29 22:15:53 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/lexer1.h"

void	start(t_status *status, t_data *data, char **line, t_list *buffer_lst)
{
	if (**line == '\0')
	{
		*status = FINISH;
		return ;
	}
	else if (**line == '$')
	{
		expand(status, data, line, buffer_lst);
		return ;
	}
	else if (**line == ' ')
		*status = START;
	else if (**line == '|')
		*status = MAKING_PIPE;
	else if (**line == '<')
		*status = MAKING_DLESS;
	else if (**line == '>')
		*status = MAKING_GREAT;
	else if (**line == '\'')
		*status = QUOTE_OPEN;
	else if (**line == '\"')
		*status = DQUOTE_OPEN;
	else
		*status = MAKING_WORD;
	(*line)++;
}
