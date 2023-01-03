/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:02:13 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/03 13:36:04 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/lexer.h"

void	init(t_state *state, t_data *data, t_list *buf_list, int *idx)
{
	list_init(buf_list);
	(*idx) = 0;
	*state = BRANCH;
	(t_unused)data;
}
