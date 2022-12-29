/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:45:08 by jincpark          #+#    #+#             */
/*   Updated: 2022/12/29 18:57:33 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/lexer2.h"

int	is_redir(t_data *data, t_node *node)
{
	t_type	cur_type;
	t_type	next_type;

	cur_type = ((t_token *)node->content)->type;
	next_type = ((t_token *)node->next->content)->type;
	if (cur_type == T_LESS || cur_type == T_GREAT
		|| cur_type == T_DLESS || cur_type == T_DGREAT)
	{
		if (next_type == T_WORD)
			return (1);
		syntax_err(data); // 현재 노드가 리다이렉션이지만 다음이 워드가 아닌 경우
		return (-1);
	}
	return (0);
}

void	parse_cmd_word(t_data *data, t_proc_data *proc_data, t_node *node)
{
	t_token	*token;

	token = (t_token *)node->content;
	if (token->type == T_WORD)
		lst_append(&proc_data->cmd_lst, new_node((void *)token->value)); 
	// ㄴ cmd_lst 의 경우 node의 content에 문자열 포인터를 바로 삽입
	else
	{
		syntax_err(data);
		return ;
	}
}


void	parse_io_file(t_data *data, t_proc_data *proc_data, t_node *redir_node, t_node *fname_node)
{
	t_redir	*redir;
	t_type	redir_type;

	redir = ft_calloc(1, sizeof(t_redir));
	lst_append(&proc_data->redir_lst, new_node((void *)redir));
	redir_type = ((t_token *)redir_node->content)->type;
	if (redir_type == T_LESS)
		redir->type = T_LESS;
	else if (redir_type == T_GREAT)
		redir->type = T_GREAT;
	else if (redir_type == T_DGREAT)
		redir->type = T_DGREAT;
	redir->fname = (char *)(((t_token *)fname_node->content)->value);
}

void	parse_io_here(t_data *data, t_proc_data *proc_data, t_node *redir_node, t_node *limiter_node)
{

}

void	parse_io_redirect(t_data *data, t_proc_data *proc_data,
		t_node *redir_node, t_node *fname_node)
{
	if (((t_token *)redir_node->content)->type == T_DLESS)
		parse_io_here(data, proc_data, redir_node, fname_node);
	else
		parse_io_file(data, proc_data, redir_node, fname_node);
}


void	parse_cmd_prefix(t_data *data, t_proc_data *proc_data, t_node *first, t_node *last)
{
	if (first == last->next) // prefix가 없는 경우
		return ;
	parse_cmd_prefix(data, proc_data, first, last->prev->prev);
	parse_io_redirect(data, proc_data, last->prev, last);
}

void	parse_cmd_suffix(t_data *data, t_proc_data *proc_data, t_node *first, t_node *last)
{
	if (first == last->next) // suffix가 없는 경우
		return ;
	if (is_redir(data, last->prev))
	{
		// REDIR WORD 인 경우
		parse_cmd_suffix(data, proc_data, first, last->prev->prev);
		parse_io_redirect(data, proc_data, last->prev, last);
	}
	else
	{
		// last->prev->type == T_WORD 인 경우
		parse_cmd_suffix(data, proc_data, first, last->prev);
		parse_cmd_word(data, proc_data, last);
	}
}

void	parse_simple_cmd(t_data *data, t_node *first, t_node *last)
{
	t_proc_data	*proc_data;
	t_node		*cur_node;

	if (first->prev == last) // 재귀로 들어올 때 last == cur_node 인 경우. ex) ls |
	{
		syntax_err(data);
		return ;
	}
	proc_data = ft_calloc(1, sizeof(t_proc_data));
	lst_init(&proc_data->cmd_lst);
	lst_init(&proc_data->redir_lst);
	lst_append(&data->proc_data_lst, new_node((void *)proc_data));
	cur_node = first;
	while (is_redir(data, cur_node) == 1)
		cur_node = cur_node->next->next;
	if (is_redir(data, cur_node) == -1)
		return ;
	parse_cmd_prefix(data, proc_data, first, cur_node->prev);
	parse_cmd_word(data, proc_data, cur_node);
	parse_cmd_suffix(data, proc_data, cur_node->next, last);
}

void	parse_expression(t_data *data, t_node *first, t_node *last)
{
	t_node	*cur_node;
	t_token	*token;

	if (last->next == first) // 재귀로 들어올 때 first == cur_node 인 경우. ex) | ls
	{
		syntax_err(data);
		return ;
	}
	cur_node = last;
	while (cur_node->prev != NULL)
	{
		token = (t_token *)cur_node->content;
		if (token->type == T_PIPE)
		{
			parse_expression(data, first, cur_node->prev);
			parse_simple_cmd(data, cur_node->next, last);
			return ;
		}
		cur_node = cur_node->prev;
	}
	parse_simple_cmd(data, first, last);
}
