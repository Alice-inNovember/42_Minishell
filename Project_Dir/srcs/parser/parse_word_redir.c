/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word_redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:34:51 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/05 16:35:39 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	list_clear_and_free(token_list, del_s_token);
}

void	parse_io_file(t_data *data, t_proc_data *proc_data, t_list *token_list)
{
	t_redir	*redir;
	t_type	type;
	t_token	*fname_token;
	char	*fname;

	if (is_return_case(data, token_list, E_NONE))
		return ;
	redir = ft_calloc(1, sizeof(t_redir));
	list_append(&proc_data->redir_list, new_node((void *)redir));
	type = ((t_token *)list_peek_first_content(token_list))->type;
	set_redir_type(redir, type);
	fname_token = (t_token *)list_peek_last_content(token_list);
	if (is_redir(fname_token->type))
		set_redir_err_flag(data, fname_token);
	else
		fname = ft_strdup((char *)fname_token->value);
	list_clear_and_free(token_list, del_s_token);
}

void	parse_io_redirect(t_data *data, t_proc_data *proc_data, t_list *token_list)
{
	if (((t_token *)list_peek_first_content(token_list))->type == T_DLESS)
		parse_io_here(data, proc_data, token_list);
	else
		parse_io_file(data, proc_data, token_list);
}
