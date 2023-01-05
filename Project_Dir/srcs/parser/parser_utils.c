/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:13:38 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/05 16:22:39 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*sub_token_list(t_node *first, t_node *last)
{
	t_list	*new_list;
	t_node	*curr;
	t_token	*token_cp;

	if (first == NULL || last == NULL
		|| first->next == NULL || last->prev == NULL)
		return (NULL);
	new_list = ft_calloc(1, sizeof(t_list));
	list_init(new_list);
	curr = first;
	while (curr != last->next)
	{
		token_cp = ft_calloc(1, sizeof(t_token));
		token_cp->type = ((t_token *)curr->content)->type;
		if (token_cp->type == T_WORD)
			token_cp->value = ft_strdup(((t_token *)curr->content)->value);
		list_append(new_list, new_node((void *)token_cp));
		curr = curr->next;
	}
	return (new_list);
}

void	list_clear_and_free(t_list *list, void del(void *))
{
	list_clear(list, del);
	free(list);
}

t_token	*get_token(t_node *node)
{
	return ((t_token *)node->content);
}

t_proc_data	*new_proc_data(void)
{
	t_proc_data	*new_proc_data;

	new_proc_data = ft_calloc(1, sizeof(t_proc_data));
	list_init(&new_proc_data->cmd_list);
	list_init(&new_proc_data->redir_list);
	return (new_proc_data);
}

t_node	*get_cmd_node(t_data *data, t_list *token_list)
{
	t_node	*curr;

	curr = list_peek_first_node(token_list);
	while (is_redir_form(data, curr))
		curr = curr->next->next;
	return (curr);
}
