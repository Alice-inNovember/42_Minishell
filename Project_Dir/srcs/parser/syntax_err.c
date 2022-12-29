/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:48:29 by jincpark          #+#    #+#             */
/*   Updated: 2022/12/29 17:00:05 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data.h"

void	del_s_token(void **content)
{
	const t_token	**token;

	token = (const t_token **)content;
	ft_free(&(*token)->value);
	ft_free(token);
}

void	del_s_cmd(void **content)
{
	const char	**cmd;

	cmd = (const char **)content;
	ft_free(cmd);
}

void	del_s_redir(void **content)
{
	const t_redir	**redir;

	redir = (const t_redir **)content;
	ft_free(&(*redir)->fname);
	ft_free(redir);
}

void	del_proc_data(void **content)
{
	const t_proc_data	**proc_data;

	proc_data = (const t_proc_data **)content;
	lst_clear(&(*proc_data)->cmd_lst, del_s_cmd);
	lst_clear(&(*proc_data)->redir_lst, del_s_redir);
	ft_free(proc_data);
}

void	syntax_err(t_data *data)
{
	data->syntax_err_flag = 1;
	lst_clear(&data->token_lst, del_s_token);
	lst_clear(&data->proc_data_lst, del_proc_data);
	printf("error : syntax error\n");
}
