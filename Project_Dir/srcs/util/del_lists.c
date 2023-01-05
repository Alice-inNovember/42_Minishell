/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:10:20 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/05 09:30:51 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	del_s_token(void *content)
{
	t_token	*token;

	token = content;
	free(token->value);
	free(token);
}

void	del_s_cmd(void *content)
{
	char	*cmd;

	cmd = content;
	free(cmd);
}

void	del_s_redir(void *content)
{
	t_redir	*redir;

	redir = content;
	free(redir->fname);
	free(redir);
}

void	del_s_proc_data(void *content)
{
	t_proc_data	*proc_data;

	proc_data = content;
	list_clear(&proc_data->cmd_list, del_s_cmd);
	list_clear(&proc_data->redir_list, del_s_redir);
	free(proc_data);
}
