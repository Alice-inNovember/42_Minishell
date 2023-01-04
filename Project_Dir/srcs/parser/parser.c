/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:45:08 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/04 15:04:51 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/lexer.h"

int	is_err_occured(t_data *data)
{
	return (data->syntax_err_flag != E_NONE);
}

int	is_syntax_err(t_list *token_list, t_error flag)
{
	return (token_list == NULL && flag != E_NONE);
}

int	is_token_list_empty(t_list *token_list)
{
	return (token_list == NULL);
}

int	is_return_case(t_data *data, t_list *token_list, t_error flag)
{
	if (is_err_occured(data))
	{
		if (token_list != NULL)
			list_clear(token_list, del_s_token);
		return (1);
	}
	if (is_syntax_err(token_list, flag))
	{
		data->syntax_err_flag = flag;
		return (1);
	}
	if (is_token_list_empty(token_list))
		return (1);
	return (0);
}

int	is_redir(t_type type)
{
	if (type == T_LESS || type == T_GREAT || type == T_DLESS || type == T_DGREAT)
		return (1);
	return (0);
}

int	is_redir_correct(t_data *data, t_node *node)
{
	t_type	cur_type;
	t_token	*next_token;

	if (node->content == NULL)
		return (0);
	cur_type = ((t_token *)node->content)->type;
	if (is_redir(cur_type))
	{
		next_token = (t_token *)node->next->content;
		if (next_token && next_token->type == T_WORD)
			return (1);
		if (next_token == NULL)
			data->syntax_err_flag = E_NEAR_NEWLINE;
	}
	return (0);
}

void	set_redir_err_flag(t_data *data, t_token *token)
{
	if (token->type == T_GREAT)
		data->syntax_err_flag = E_NEAR_GREAT;
	else if (token->type == T_LESS)
		data->syntax_err_flag = E_NEAR_LESS;
	else if (token->type == T_DGREAT)
		data->syntax_err_flag = E_NEAR_DGREAT;
	else if (token->type == T_DLESS)
		data->syntax_err_flag = E_NEAR_DLESS;
}

void	parse_cmd_word(t_data *data, t_proc_data *proc_data, t_list *token_list)
{
	t_token	*token;
	char	*cmd_word;

	if (is_return_case(data, token_list, E_NONE))
		return ;
	token = list_peek_first_content(token_list);
	if (token->type == T_WORD)
	{
		cmd_word = ft_strdup((char *)token->value);
		list_append(&proc_data->cmd_list, new_node((void *)cmd_word)); 
	}
	else
		set_redir_err_flag(data, token);
	list_clear(token_list, del_s_token);
}


void	parse_io_file(t_data *data, t_proc_data *proc_data, t_list *token_list)
{
	t_redir	*redir;
	t_type	redir_type;
	char	*fname;

	if (is_return_case(data, token_list, E_NONE))
		return ;
	redir = ft_calloc(1, sizeof(t_redir));
	list_append(&proc_data->redir_list, new_node((void *)redir));
	redir_type = ((t_token *)list_peek_first_content(token_list))->type;
	if (redir_type == T_LESS)
		redir->type = T_LESS;
	else if (redir_type == T_GREAT)
		redir->type = T_GREAT;
	else
		redir->type = T_DGREAT;
	fname = ft_strdup((char *)(((t_token *)list_peek_last_content(token_list))->value));
	list_clear(token_list, del_s_token);
}

void	parse_io_here(t_data *data, t_proc_data *proc_data, t_list *token_list)
{

}

void	parse_io_redirect(t_data *data, t_proc_data *proc_data, t_list *token_list)
{
	if (((t_token *)list_peek_first_content(token_list))->type == T_DLESS)
		parse_io_here(data, proc_data, token_list);
	else
		parse_io_file(data, proc_data, token_list);
}


void	parse_cmd_prefix(t_data *data, t_proc_data *proc_data, t_list *token_list)
{
	t_node	*first;
	t_node	*last;

	if (is_return_case(data, token_list, E_NONE))
		return ;
	first = list_peek_first_node(token_list);
	last = list_peek_last_node(token_list);
	parse_cmd_prefix(data, proc_data, sub_token_list(data, first, last->prev->prev));
	parse_io_redirect(data, proc_data, sub_token_list(data, last->prev, last));
	list_clear(token_list, del_s_token);
}

void	parse_cmd_suffix(t_data *data, t_proc_data *proc_data, t_list *token_list)
{
	t_node	*first;
	t_node	*last;

	if (is_return_case(data, token_list, E_NONE))
		return ;
	first = list_peek_first_node(token_list);
	last = list_peek_last_node(token_list);
	if (is_redir_correct(data, last->prev))
	{
		parse_cmd_suffix(data, proc_data, sub_token_list(data, first, last->prev->prev));
		parse_io_redirect(data, proc_data, sub_token_list(data, last->prev, last));
		list_clear(token_list, del_s_token);
	}
	else
	{
		parse_cmd_suffix(data, proc_data, sub_token_list(data, first, last->prev));
		if (is_redir(((t_token *)last->content)->type))
			data->syntax_err_flag = E_NEAR_NEWLINE;
		parse_cmd_word(data, proc_data, sub_token_list(data, last, last));
		list_clear(token_list, del_s_token);
	}
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
	while (is_redir_correct(data, curr))
		curr = curr->next->next;
	return (curr);
}

void	parse_simple_cmd(t_data *data, t_list *token_list)
{
	t_node		*first;
	t_node		*cmd_node;
	t_node		*last;
	t_proc_data	*proc_data;

	if (is_return_case(data, token_list, E_NEAR_PIPE))
		return ;
	proc_data = new_proc_data();
	list_append(&data->proc_data_list, new_node((void *)proc_data));
	first = list_peek_first_node(token_list);
	cmd_node = get_cmd_node(data, token_list);
	if (cmd_node == NULL)
		return ;
	last = list_peek_last_node(token_list);
	parse_cmd_prefix(data, proc_data, sub_token_list(data, first, cmd_node->prev));
	parse_cmd_word(data, proc_data, sub_token_list(data, cmd_node, cmd_node));
	parse_cmd_suffix(data, proc_data, sub_token_list(data, cmd_node->next, last));
	list_clear(token_list, del_s_token);
}

void	parse_expression(t_data *data, t_list *token_list)
{
	t_node	*first;
	t_node	*last;
	t_node	*curr;

	if (is_return_case(data, token_list, E_NEAR_PIPE))
		return ;
	first = list_peek_first_node(token_list);
	last = list_peek_last_node(token_list);
	curr = last;
	while (curr->prev != NULL)
	{
		if (((t_token *)curr->content)->type == T_PIPE)
		{
			parse_expression(data, sub_token_list(data, first, curr->prev));
			parse_simple_cmd(data, sub_token_list(data, curr->next, last));
			list_clear(token_list, del_s_token);
			return ;
		}
		curr = curr->prev;
	}
	parse_simple_cmd(data, sub_token_list(data, first, last));
	list_clear(token_list, del_s_token);
}
