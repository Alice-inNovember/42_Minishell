/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:13:42 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/29 21:07:36 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/lexer1.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	char	*line;

	envp_init(&data.envp_lst, envp);
	while (1)
	{
		line = readline("minishell>");
		tokenize(&data, line);
		print_token_lst(&data.token_lst);
		lst_init(&data.proc_data_lst);
		data.syntax_err_flag = 0;
		parse_expression(&data, data.token_lst.head->next, data.token_lst.tail->prev);
		if (data.syntax_err_flag == 1)
			continue;
		lst_clear(&data.token_lst, del_s_token);
		lst_clear(&data.proc_data_lst, del_proc_data);
	}
	return (0);
}
