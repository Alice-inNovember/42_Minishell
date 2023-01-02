/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:18:51 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/30 14:34:54 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/lexer1.h"

void	quote_error(t_status *status, t_data *data, char **line, t_list *buffer_lst)
{
	printf("Syntax error: open dquote\n");
	*status = FINISH;
}
