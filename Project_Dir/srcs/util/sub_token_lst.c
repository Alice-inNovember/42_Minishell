/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_token_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:13:38 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/02 20:48:26 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_head_or_tail(t_node *first, t_node *last)
{
	return (first->next == NULL || last->prev == NULL);
}

t_list	*sub_token_lst(t_node *first, t_node *last)
{
	t_list	*new_lst;
	t_node	*cur_node;
	t_token	*token_cp;

	if (is_head_or_tail(old_lst, first, last))
		return (NULL);
	lst_init(&new_lst);
	cur_node = first;
	while (cur_node->next != NULL)
	{
		token_cp = ft_calloc(1, sizeof(t_token));
		token_cp->type = ((t_token *)cur_node->content)->type;
		token_cp->value = ft_strdup(((t_token *)cur_node->content)->value);
		lst_append(new_list, new_node((void *)token_cp));
		cur_node = cur_node->next;
	}
	return (new_list);
}
