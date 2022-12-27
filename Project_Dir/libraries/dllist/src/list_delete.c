/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:06:46 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/26 19:55:47 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doubly_linked_list.h"

void	lst_delete(t_node *node, void (*del)(void *))
{
	t_node	*prev_node;
	t_node	*next_node;

	prev_node = node->prev;
	next_node = node->next;
	del(node->content);
	ft_free(node);
	prev_node->next = next_node;
	next_node->prev = prev_node;
}

void	lst_delete_first(t_list *list, void (*del)(void *))
{
	t_node	*first_node;
	t_node	*prev_node;
	t_node	*next_node;

	first_node = list->head->next;
	prev_node = first_node->prev;
	next_node = first_node->next;
	del(first_node->content);
	ft_free(first_node);
	prev_node->next = next_node;
	next_node->prev = prev_node;
}

void	lst_delete_last(t_list *list, void (*del)(void *))
{
	t_node	*last_node;
	t_node	*prev_node;
	t_node	*next_node;

	last_node = list->head->next;
	prev_node = last_node->prev;
	next_node = last_node->next;
	del(last_node->content);
	ft_free(last_node);
	prev_node->next = next_node;
	next_node->prev = prev_node;
}

void	lst_clear(t_list *list, void (*del)(void *))
{
	t_node	*current_node;
	t_node	*next_node;

	current_node = list->head->next;
	while (current_node->next != NULL)
	{
		next_node = current_node->next;
		if (del != NULL)
			del(current_node->content);
		ft_free(current_node);
		current_node = next_node;
	}
	ft_free(list->head);
	ft_free(list->tail);
}
