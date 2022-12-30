/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:19:12 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/30 11:40:13 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/lexer1.h"

void	making_pipe(t_status *status, t_data *data, char **line, t_list *buffer_lst)
{
	create_token(&data->token_lst, buffer_lst, T_PIPE);
	*status = BRANCH;
	(*line)++;
}
