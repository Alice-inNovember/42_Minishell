/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:45:08 by jincpark          #+#    #+#             */
/*   Updated: 2022/12/27 15:57:35 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * t_list
 * {
 * 		t_node *head;
 * 		t_node *tail;
 * 		int		size;
 * }
 *
 * t_node
 * {
 * 		void	*content;
 * 		t_node	*prev;
 * 		t_node	*next;
 * }
 *
 * t_token
 * {
 * 		t_type			type;
 * 		t_quote_type	quote_type;
 * 		char			*value;
 * }
 */

void	parse_simple_cmd(t_node *first, t_node *last)
{
}

void	parse_expression(t_node *first, t_node *last)
{
	t_node	*cur_node;
	t_token	*token;

	cur_node = last;
	while (cur_node->prev != NULL)
	{
		token = (t_token *)node->content;
		if (token->type == T_PIPE)
		{
			parse_simple_cmd(cur_node->next, last);
			parse_expression(first, cur_node->prev);
			return ;
		}
		cur_node = cur_node->prev;
	}
	parse_simple_cmd(first, last);
}

