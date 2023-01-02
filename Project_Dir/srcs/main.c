/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:13:42 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/02 23:32:43 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/lexer1.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	envp_init(&data.envp_lst, envp);
	while (1)
	{
		data.line = readline("minishell> ");
		tokenize(&data, data.line);
		print_token_lst(&data.token_lst);
		lst_init(&data.proc_data_lst);
		data.syntax_err_flag = 0;
		parse_expression(&data, &data.token_lst);
		if (data.syntax_err_flag == 1)
			continue ;
		// executor();
		lst_clear(&data.proc_data_lst, del_s_proc_data);
	}
	return (0);
}
