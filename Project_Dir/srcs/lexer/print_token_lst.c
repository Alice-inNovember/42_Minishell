/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:45:32 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/28 11:00:05 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/lexer1.h"

void	print_token_lst(t_list *token_lst)
{
	t_node	*cur_node;

	cur_node = lst_peek_first(token_lst);
	while (cur_node->next != NULL)
	{
		
		cur_node = cur_node->next;
	}
}
