/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:25:56 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/25 15:07:31 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doubly_linked_list.h"

void	lst_init(t_list *list)
{
	list->head = (t_node *)ft_calloc(1, sizeof(t_node));
	list->tail = (t_node *)ft_calloc(1, sizeof(t_node));
	list->head->next = list->tail;
	list->tail->prev = list->head;
	list->size = 0;
}

t_node	*new_node(void *content)
{
	t_node	*new_node;

	new_node = (t_node *)ft_calloc(1, sizeof(t_node));
	new_node->content = content;
	return (new_node);
}

int	lst_isempty(t_list *list)
{
	if (list->size == 0)
		return (1);
	else
		return (0);
}

int	lst_size(t_list *list)
{
	return (list->size);
}
