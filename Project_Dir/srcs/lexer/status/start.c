/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:15:22 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/30 13:55:03 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/lexer1.h"

void	branch(t_status *status, t_data *data, char **line, t_list *buffer_lst)
{
	if (**line == ' ')
	{
		*status = BRANCH;
		(*line)++;
	}
	else if (**line == '\0')
		*status = FINISH;
	else if (**line == '$')
		*status = EXPAND;
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
}
