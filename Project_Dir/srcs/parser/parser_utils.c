/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:13:38 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/02 22:52:15 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_head_or_tail(t_node *first, t_node *last)
{
	return (first->next == NULL || last->prev == NULL);
}

t_list	*sub_token_lst(t_data *data, t_node *first, t_node *last)
{
	t_list	*new_list;
	t_node	*curr;
	t_token	*token_cp;

	if (is_head_or_tail(first, last))
		return (NULL);
	new_list = ft_calloc(1, sizeof(t_list));
	lst_init(new_list);
	curr = first;
	while (curr != last->next)
	{
		token_cp = ft_calloc(1, sizeof(t_token));
		token_cp->type = ((t_token *)curr->content)->type;
		token_cp->value = ft_strdup(((t_token *)curr->content)->value);
		lst_append(new_list, new_node((void *)token_cp));
		curr = curr->next;
	}
	return (new_list);
}
