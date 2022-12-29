/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_dless.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:18:59 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/29 16:18:11 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/lexer1.h"

void	making_dless(t_status *status, t_data *data, char **line, t_list *buffer_lst)
{
	create_token(&data->token_lst, buffer_lst, T_DLESS);
	*status = START;
}
