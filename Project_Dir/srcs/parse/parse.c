/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:45:08 by jincpark          #+#    #+#             */
/*   Updated: 2022/12/28 04:17:33 by jincpark         ###   ########.fr       */
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
 *
 * t_proc_data
 * {
 * 		t_list	cmd_lst;
 * 		t_list	redir_lst;
 * 		t_list	envp_lst;
 * 		...
 * }
 */

int	is_redir(t_node *node)
{
	if (node->type == T_LESS || node->type == T_GREAT
		|| node->type == T_DESS || node->type == T_DGREAT)
	{
		if (node->next->type == T_WORD)
			return (1);
		syntax_err(); // 현재 노드가 리다이렉션이지만 다음이 워드가 아닌 경우
	}
	return (0);
}

void	parse_cmd_prefix(t_proc_data *proc_data, t_node *first, t_node *last)
{
	if (last->next == first) // prefix가 없는 경우
		return ;
	parse_cmd_prefix(proc_data, first, last->prev->prev);
	parse_io_redirect(proc_data, last->prev, last);
}

void	parse_cmd_suffix(t_proc_data *proc_data, t_node *first, t_node *last)
{
	if (first->prev == last) // suffix가 없는 경우
		return ;
	if (is_redir(last->prev))
	{
		// REDIR WORD 인 경우
		parse_cmd_suffix(proc_data, first, last->prev->prev);
		parse_io_redirect(proc_data, last->prev, last);
	}
	else
	{
		// last->prev->type == T_WORD 인 경우
		parse_cmd_suffix(proc_data, first, last->prev);
		if (last->type == T_WORD)
			parse_cmd_word(proc_data, last);
		else // WORD REDIR 인 경우
			syntax_error();
	}
}

void	parse_io_here(t_proc_data *proc_data, t_node *redir_node, t_node *limiter_node)
{
}

void	parse_io_file(t_proc_data *proc_data, t_node *redir_node, t_node *fname_node)
{
	if (redir_node->type == T_LESS)
		//...
	else if (redir_node->type == T_GREAT)
		//...
	else if (redir_node->type == T_DGREAT)
		//...
}

void	parse_io_redirect(t_proc_data *proc_data, t_node *redir_node, t_node *fname_node)
{
	if (redir_node->type == DLESS)
		parse_io_here(proc_data, redir_node, fname_node);
	else
		parse_io_file(proc_data, redir_node, fname_node);
}

void	parse_cmd_word(t_proc_data *proc_data, t_node *node)
{
	if (node->type == T_WORD)
		lst_append(proc_data->cmd_lst, new_node((void *)node->content->value));
}

void	parse_simple_cmd(t_list *proc_data_lst, t_node *first, t_node *last)
{
	t_proc_data	*proc_data;
	t_node		*cur_node;

	if (first->prev == last) // 재귀로 들어올 때 last == cur_node 인 경우. ex) ls |
		syntax_err();
	init_proc_data(proc_data); // calloc 0
	lst_append(proc_data_lst, new_node((void *)proc_data));
	cur_node = first;
	while (is_redir(cur_node))
		cur_node = cur_node->next->next;
	parse_cmd_prefix(proc_data, first, cur_node->prev);
	parse_cmd_word(proc_data, cur_node);
	parse_cmd_suffix(proc_data, cur_node->next, last);
}

void	parse_expression(t_list *proc_data_lst, t_node *first, t_node *last)
{
	t_node	*cur_node;
	t_token	*token;

	if (last->next == first) // 재귀로 들어올 때 first == cur_node 인 경우. ex) | ls
		syntax_err();
	cur_node = last;
	while (cur_node->prev != NULL)
	{
		token = (t_token *)cur_node->content;
		if (token->type == T_PIPE)
		{
			parse_expression(proc_data_lst, first, cur_node->prev);
			parse_simple_cmd(proc_data_lst, cur_node->next, last);
			return ;
		}
		cur_node = cur_node->prev;
	}
	parse_simple_cmd(first, last);
}
