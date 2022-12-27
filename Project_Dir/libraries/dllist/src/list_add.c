/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:01:14 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/27 17:35:34 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dllist.h"

void	lst_prepend(t_list *list, t_node *new_node)
{
	t_node	*first_node;

	first_node = list->head->next;
	list->head->next = new_node;
	new_node->prev = list->head;
	new_node->next = first_node;
	first_node->prev = new_node;
	(list->size)++;
}

void	lst_append(t_list *list, t_node *new_node)
{
	t_node	*last_node;

	last_node = list->tail->prev;
	list->tail->prev = new_node;
	new_node->next = list->tail;
	new_node->prev = last_node;
	last_node->next = new_node;
	(list->size)++;
}
