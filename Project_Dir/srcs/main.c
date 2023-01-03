/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:13:42 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/03 10:12:13 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_data(t_data *data, char **envp)
{
	lst_init(&data->token_lst);
	lst_init(&data->proc_data_lst);
	lst_init(&data->builtin_lst);
	lst_init(&data->pid_lst);
	data->syntax_err_flag = 0;
}

void	clear_data(t_data *data)
{
	lst_clear(&data->token_lst, del_token);
	lst_clear(&data->proc_data_lst, del_proc_data);
	lst_clear(&data->builtin_lst, del_builtin);
	lst_clear(&data->pid_lst, del_pid);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	envp_init(&data.envp_lst, envp);
	while (1)
	{
		init_data(&data, envp);
		data.line = readline("minishell>");
		make_token_list(&data);
		//parse_expression(&data, &data.token_lst);
		//if (data.syntax_err_flag == 1)
		//	continue ;
		//executor();
		clear_data(&data);
	}
	return (0);
}
