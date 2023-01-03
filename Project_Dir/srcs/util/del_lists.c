/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:10:20 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/03 13:36:10 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	del_s_token(void **content)
{
	t_token	**token;

	token = (t_token **)content;
	ft_free((void **)&(*token)->value);
	ft_free((void **)token);
}

void	del_s_cmd(void **content)
{
	char	**cmd;

	cmd = (char **)content;
	ft_free((void **)cmd);
}

void	del_s_redir(void **content)
{
	t_redir	**redir;

	redir = (t_redir **)content;
	ft_free((void **)&(*redir)->fname);
	ft_free((void **)redir);
}

void	del_s_proc_data(void **content)
{
	t_proc_data	**proc_data;

	proc_data = (t_proc_data **)content;
	list_clear(&(*proc_data)->cmd_list, del_s_cmd);
	list_clear(&(*proc_data)->redir_list, del_s_redir);
	ft_free((void **)proc_data);
}
