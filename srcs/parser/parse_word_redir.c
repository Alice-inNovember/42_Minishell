/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word_redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:34:51 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/13 10:00:23 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/util.h"

void	parse_cmd_word(t_data *data, t_proc_data *proc_data, t_list *token_list)
{
	t_token	*token;
	char	*cmd_word;

	if (is_return_case(data, token_list, E_NONE))
		return ;
	token = list_peek_first_content(token_list);
	cmd_word = ft_strdup((char *)token->value);
	list_append(&proc_data->cmd_list, new_node((void *)cmd_word));
	clear_and_free_token_list(token_list);
}

void	parse_io_file(t_data *data, t_proc_data *proc_data, t_list *token_list)
{
	t_redir	*redir;
	t_type	type;
	void	*filename;

	if (is_return_case(data, token_list, E_NONE))
		return ;
	redir = ft_calloc(1, sizeof(t_redir));
	type = ((t_token *)list_peek_first_content(token_list))->type;
	filename = ((t_token *)list_peek_last_content(token_list))->value;
	set_s_redir(redir, type, (char *)filename);
	list_append(&proc_data->redir_list, new_node((void *)redir));
	clear_and_free_token_list(token_list);
}

void	parse_redirect(t_data *data, t_proc_data *proc_data, t_list *token_list)
{
	t_token	*first_token;
	t_token	*second_token;

	first_token = (t_token *)list_peek_first_content(token_list);
	second_token = (t_token *)list_peek_last_content(token_list);
	if (is_redir(second_token->type))
		set_redir_err_flag(data, second_token);
	if (first_token->type == T_DLESS)
		parse_io_here(data, proc_data, token_list);
	else
		parse_io_file(data, proc_data, token_list);
}
