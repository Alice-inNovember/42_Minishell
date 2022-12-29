/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:48:29 by jincpark          #+#    #+#             */
/*   Updated: 2022/12/29 17:13:17 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data.h"

void	syntax_err(t_data *data)
{
	data->syntax_err_flag = 1;
	lst_clear(&data->token_lst, del_s_token);
	lst_clear(&data->proc_data_lst, del_proc_data);
	printf("error : syntax error\n");
}