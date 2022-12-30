/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_peek.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:04:29 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/30 10:04:06 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dllist.h"

t_node	*lst_peek_first_node(t_list *list)
{
	return (list->head->next);
}

t_node	*lst_peek_last_node(t_list *list)
{
	return (list->tail->prev);
}

void	*lst_peek_first_content(t_list *list)
{
	return (list->head->next->content);
}

void	*lst_peek_last_content(t_list *list)
{
	return (list->tail->prev->content);
}
