/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:11:45 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/03 20:13:04 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/lexer.h"

void	clear(t_state *state, t_data *data, t_list *buf_list, int *idx)
{
	list_clear(buf_list, del_buffer);
	ft_free((void **)&data->line);
	*state = FINISH;
	(t_unused)idx;
}
