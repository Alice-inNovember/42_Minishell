/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:06:46 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dllist.h"
#include <stdlib.h>

void	list_delete(t_node *node, void (*del)(void *))
{
	t_node	*prev_node;
	t_node	*next_node;

	prev_node = node->prev;
	next_node = node->next;
	del(node->content);
	free(node);
	prev_node->next = next_node;
	next_node->prev = prev_node;
}

void	list_delete_first(t_list *list, void (*del)(void *))
{
	t_node	*first_node;
	t_node	*prev_node;
	t_node	*next_node;

	first_node = list_peek_first_node(list);
	prev_node = first_node->prev;
	next_node = first_node->next;
	del(first_node->content);
	free(first_node);
	prev_node->next = next_node;
	next_node->prev = prev_node;
}

void	list_delete_last(t_list *list, void (*del)(void *))
{
	t_node	*last_node;
	t_node	*prev_node;
	t_node	*next_node;

	last_node = list_peek_last_node(list);
	prev_node = last_node->prev;
	next_node = last_node->next;
	del(last_node->content);
	free(last_node);
	prev_node->next = next_node;
	next_node->prev = prev_node;
}

void	list_clear(t_list *list, void (*del)(void *))
{
	t_node	*current_node;
	t_node	*next_node;

	current_node = list_peek_first_node(list);
	while (current_node->next != NULL)
	{
		next_node = current_node->next;
		if (del != NULL)
			del(current_node->content);
		free(current_node);
		current_node = next_node;
	}
	free(list->head);
	free(list->tail);
}
