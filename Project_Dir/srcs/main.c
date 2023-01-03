/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:13:42 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/03 22:03:49 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_data(t_data *data)
{
	list_init(&data->token_list);
	list_init(&data->proc_data_list);
	list_init(&data->builtin_list);
	list_init(&data->pid_list);
	data->syntax_err_flag = 0;
}

void	clear_data(t_data *data)
{
	list_clear(&data->token_list, del_s_token);
	list_clear(&data->proc_data_list, del_s_proc_data);
	list_clear(&data->builtin_list, NULL);
	list_clear(&data->pid_list, NULL);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	envp_init(&data.envp_list, envp);
	while (1)
	{
		init_data(&data);
		data.line = readline("minishell>");
		make_token_list(&data);
		print_token_lst(&data.token_list);
		//parse_expression(&data, &data.token_list);
		//if (data.syntax_err_flag == 1)
		//	continue ;
		//executor();
		clear_data(&data);
	}
	return (0);
}
