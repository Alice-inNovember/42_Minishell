/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 09:06:43 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/30 11:40:08 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/lexer1.h"

void	expand(t_status *status, t_data *data, char **line, t_list *buffer_lst)
{
	if (is_h)
	{
		*status = MAKING_WORD;
		return ;
	}
}
