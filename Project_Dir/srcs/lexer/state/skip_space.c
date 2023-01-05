/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:23:10 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/05 20:24:20 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/lexer.h"

void	skip_space(t_state *state, t_data *data, t_list *buf_list, int *idx)
{
	(*idx)++;
	*state = BRANCH;
	(t_unused)data;
	(t_unused)buf_list;
}
