/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_return_cases.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:11:19 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/13 10:00:23 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

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
			clear_and_free_token_list(token_list);
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
