/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_peek.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:04:29 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dllist.h"

t_node	*list_peek_first_node(t_list *list)
{
	return (list->head->next);
}

t_node	*list_peek_last_node(t_list *list)
{
	return (list->tail->prev);
}

void	*list_peek_first_content(t_list *list)
{
	return (list->head->next->content);
}

void	*list_peek_last_content(t_list *list)
{
	return (list->tail->prev->content);
}
