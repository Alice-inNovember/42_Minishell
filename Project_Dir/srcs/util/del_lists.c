/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:10:20 by jincpark          #+#    #+#             */
/*   Updated: 2022/12/29 18:53:16 by jincpark         ###   ########.fr       */
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

void	del_proc_data(void **content)
{
	t_proc_data	**proc_data;

	proc_data = (t_proc_data **)content;
	lst_clear(&(*proc_data)->cmd_lst, del_s_cmd);
	lst_clear(&(*proc_data)->redir_lst, del_s_redir);
	ft_free((void **)proc_data);
}
