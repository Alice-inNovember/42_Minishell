/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:45:08 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/02 23:44:28 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/lexer2.h"

int	is_err_occured(t_data *data, t_list *token_lst)
{
	return (data->syntax_err_flag == 1 || token_lst == NULL);
}

int	is_redir(t_data *data, t_node *node)
{
	t_type	cur_type;
	t_token	*next_token;

	if (node->content == NULL)
		return (0);
	cur_type = ((t_token *)node->content)->type;
	if (cur_type == T_LESS || cur_type == T_GREAT
		|| cur_type == T_DLESS || cur_type == T_DGREAT)
	{
		next_token = (t_token *)node->next->content;
		if (next_token && next_token->type == T_WORD)
			return (1);
		syntax_err(data);
		return (-1);
	}
	return (0);
}

void	parse_cmd_word(t_data *data, t_proc_data *proc_data, t_list *token_lst)
{
	t_token	*token;
	char	*cmd_word;

	if (is_err_occured(data, token_lst))
		return ;
	token = lst_peek_first_content(token_lst);
	cmd_word = ft_strdup((char *)token->value);
	lst_append(&proc_data->cmd_lst, new_node((void *)cmd_word)); 
	lst_clear(token_lst, del_s_token);
}


void	parse_io_file(t_data *data, t_proc_data *proc_data, t_list *token_lst)
{
	t_redir	*redir;
	t_type	redir_type;
	char	*fname;

	redir = ft_calloc(1, sizeof(t_redir));
	lst_append(&proc_data->redir_lst, new_node((void *)redir));
	redir_type = ((t_token *)lst_peek_first_content(token_lst))->type;
	if (redir_type == T_LESS)
		redir->type = T_LESS;
	else if (redir_type == T_GREAT)
		redir->type = T_GREAT;
	else
		redir->type = T_DGREAT;
	fname = ft_strdup((char *)(((t_token *)lst_peek_last_content(token_lst))->value));
	lst_clear(token_lst, del_s_token);
}

void	parse_io_here(t_data *data, t_proc_data *proc_data, t_list *token_lst)
{

}

void	parse_io_redirect(t_data *data, t_proc_data *proc_data, t_list *token_lst)
{
	if (((t_token *)lst_peek_first_content(token_lst))->type == T_DLESS)
		parse_io_here(data, proc_data, token_lst);
	else
		parse_io_file(data, proc_data, token_lst);
}


void	parse_cmd_prefix(t_data *data, t_proc_data *proc_data, t_list *token_lst)
{
	t_node	*first;
	t_node	*last;

	if (is_err_occured(data, token_lst))
		return ;
	first = lst_peek_first_node(token_lst);
	last = lst_peek_last_node(token_lst);
	parse_cmd_prefix(data, proc_data, sub_token_lst(data, first, last->prev->prev));
	parse_io_redirect(data, proc_data, sub_token_lst(data, last->prev, last));
	lst_clear(token_lst, del_s_token);
}

void	parse_cmd_suffix(t_data *data, t_proc_data *proc_data, t_list *token_lst)
{
	t_node	*first;
	t_node	*last;

	if (is_err_occured(data, token_lst))
		return ;
	first = lst_peek_first_node(token_lst);
	last = lst_peek_last_node(token_lst);
	if (is_redir(data, last->prev))
	{
		parse_cmd_suffix(data, proc_data, sub_token_lst(data, first, last->prev->prev));
		parse_io_redirect(data, proc_data, sub_token_lst(data, last->prev, last));
		lst_clear(token_lst, del_s_token);
	}
	else
	{
		parse_cmd_suffix(data, proc_data, sub_token_lst(data, first, last->prev));
		parse_cmd_word(data, proc_data, sub_token_lst(data, last, last));
		lst_clear(token_lst, del_s_token);
	}
}

t_proc_data	*new_proc_data(void)
{
	t_proc_data	*new_proc_data;

	new_proc_data = ft_calloc(1, sizeof(t_proc_data));
	lst_init(&new_proc_data->cmd_lst);
	lst_init(&new_proc_data->redir_lst);
	return (new_proc_data);
}

t_node	*get_cmd_node(t_data *data, t_list *token_lst)
{
	t_node	*curr;
	int		redir_value;

	curr = lst_peek_first_node(token_lst);
	redir_value = is_redir(data, curr);
	while (redir_value == 1)
	{
		curr = curr->next->next;
		redir_value = is_redir(data, curr);
	}
	if (redir_value == -1)
		return (NULL);
	return (curr);
}

void	parse_simple_cmd(t_data *data, t_list *token_lst)
{
	t_node		*first;
	t_node		*cmd_node;
	t_node		*last;
	t_proc_data	*proc_data;

	if (token_lst == NULL)
	{
		syntax_err(data);
		return ;
	}
	if (data->syntax_err_flag == 1)
		return ;
	proc_data = new_proc_data();
	lst_append(&data->proc_data_lst, new_node((void *)proc_data));
	first = lst_peek_first_node(token_lst);
	cmd_node = get_cmd_node(data, token_lst);
	if (cmd_node == NULL)
		return ;
	last = lst_peek_last_node(token_lst);
	parse_cmd_prefix(data, proc_data, sub_token_lst(data, first, cmd_node->prev));
	parse_cmd_word(data, proc_data, sub_token_lst(data, cmd_node, cmd_node));
	parse_cmd_suffix(data, proc_data, sub_token_lst(data, cmd_node->next, last));
	lst_clear(token_lst, del_s_token);
}

void	parse_expression(t_data *data, t_list *token_lst)
{
	t_node	*first;
	t_node	*last;
	t_node	*curr;

	if (is_err_occured(data, token_lst))
		return ;
	first = lst_peek_first_node(token_lst);
	last = lst_peek_last_node(token_lst);
	curr = last;
	while (curr->prev != NULL)
	{
		if (((t_token *)curr->content)->type == T_PIPE)
		{
			parse_expression(data, sub_token_lst(data, first, curr->prev));
			parse_simple_cmd(data, sub_token_lst(data, curr->next, last));
			//lst_clear(token_lst, del_s_token);
			return ;
		}
		curr = curr->prev;
	}
	parse_simple_cmd(data, sub_token_lst(data, first, last));
	//lst_clear(token_lst, del_s_token);
}
