/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_peek.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:04:29 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/27 17:35:50 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dllist.h"

void	*lst_peek_first(t_list *list)
{
	return (list->head->next->content);
}

void	*lst_peek_last(t_list *list)
{
	return (list->tail->prev->content);
}
