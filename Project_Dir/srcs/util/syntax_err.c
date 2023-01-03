/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:48:29 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/03 13:36:11 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	syntax_err(t_data *data)
{
	if (data->syntax_err_flag == 0)
	{
		data->syntax_err_flag = 1;
		list_clear(&data->token_list, del_s_token);
		list_clear(&data->proc_data_list, del_s_proc_data);
		printf("error : syntax error\n");
	}
}
