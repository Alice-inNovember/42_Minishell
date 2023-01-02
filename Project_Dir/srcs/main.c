/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:13:42 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/02 23:32:43 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/lexer1.h"

void	init_data(t_data *data, char **envp)
{
	envp_init(&data->envp_lst, envp);
	lst_init(&data->token_lst);
	lst_init(&data->proc_data_lst);
	lst_init(&data->builtin_lst);
	lst_init(&data->pid_lst);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	init_data(&data, envp);
	while (1)
	{
		data.line = readline("minishell>");
		if (make_token_list(&data, data.line) == 1)
			break ;
		print_token_lst(&data.token_lst);
		//lst_init(&data.proc_data_lst);
		//data.syntax_err_flag = 0;
		//parse_expression(&data, &data.token_lst);
		//if (data.syntax_err_flag == 1)
		//	continue ;
    lst_clear(&data.token_lst, del_token);
    //executor();
		//lst_clear(&data.proc_data_lst, del_proc_data);
	}
	return (0);
}
