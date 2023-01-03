/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_peek.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:04:29 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/03 13:35:44 by junlee2          ###   ########seoul.kr  */
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
