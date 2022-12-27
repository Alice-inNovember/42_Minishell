/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:45:08 by jincpark          #+#    #+#             */
/*   Updated: 2022/12/27 22:57:40 by jincpark         ###   ########.fr       */
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
 * t_command
 * {
 * 		char	**cmd_vector;
 * 		t_list	infile_lst;
 * 		t_list	outfile_lst;
 * }
 *
 * t_proc_data
 * {
 * 		char	**cmd_vector;
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
		syntax_err();
	}
	return (0);
}

void	parse_cmd_prefix(t_proc_data *proc_data, t_node *first, t_node *last)
{
	t_node	*cur_node;

	if (last->next == first)
		return ;
	cur_node = first->next;
	parse_io_redirect(proc_data, first, cur_node);
	parse_cmd_prefix(proc_data, cur_node->next, last);
}

void	parse_cmd_suffix(t_proc_data *proc_data, t_node *first, t_node *last)
{
	t_node	*cur_node;

	if (first->prev == last)
		return ;
	parse_io_redirect(
}

void	parse_io_redirect(t_proc_data *proc_data, t_node *redir_node, t_node *fname_node)
{
	if (redir_node->type == DLESS)
		parse_io_here(proc_data, redir_node, fname_node);
	else
		parse_io_file(proc_data, redir_node, fname_node);
}

void	parse_io_file(t_proc_data *proc_data, t_node *redir_node, t_node *fname_node)
{
	if (redir_node->type == LESS)
		//...
	else if (redir_node->type == GREAT)
		//...
	else if (redir_node->type == DGREAT)
		//...
}

void	parse_io_here(t_proc_data *proc_data, t_node *redir_node, t_node *limiter_node)
{
}

void	parse_cmd_word(t_proc_data *proc_data, t_node *node)
{
	if (node->type == T_WORD)
		// proc_data->cmd_vector[0] = node->value;
}

void	parse_simple_cmd(t_list *proc_data_lst, t_node *first, t_node *last)
{
	t_proc_data	*proc_data;
	t_node		*cur_node;

	if (first->prev == last)
		syntax_err();
	init_proc_data(proc_data);
	lst_prepend(proc_data_lst, new_node((void *)proc_data));
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

	if (last->next == first)
		syntax_err();
	cur_node = last;
	while (cur_node->prev != NULL)
	{
		token = (t_token *)cur_node->content;
		if (token->type == T_PIPE)
		{
			parse_simple_cmd(proc_data_lst, cur_node->next, last);
			parse_expression(proc_data_lst, first, cur_node->prev);
			return ;
		}
		cur_node = cur_node->prev;
	}
	parse_simple_cmd(first, last);
}


