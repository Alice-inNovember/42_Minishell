/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:13:42 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/11 11:37:09 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include "readline/readline.h"
#include "readline/history.h"
#include "../includes/lexer.h"
#include "../includes/parser.h"
#include "../includes/envp.h"
#include "../includes/builtin.h"
#include "../includes/executor.h"
#include "../includes/signal_handler.h"
#include "../includes/util.h"

int	g_last_exit_status;

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(t_unused)argv;
	if (!check_argc(argc))
		return (1);
	printf("\n%s\
  ██╗██╗██████╗   ███╗   ███╗██╗███╗  ██╗██╗ ██████╗██╗  ██╗███████╗██╗     ██╗     \n\
 ██╔╝██║╚════██╗  ████╗ ████║██║████╗ ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     \n\
██╔╝ ██║  ███╔═╝  ██╔████╔██║██║██╔██╗██║██║╚█████╗ ███████║█████╗  ██║     ██║     \n\
███████║██╔══╝    ██║╚██╔╝██║██║██║╚████║██║ ╚═══██╗██╔══██║██╔══╝  ██║     ██║     \n\
╚════██║███████╗  ██║ ╚═╝ ██║██║██║ ╚███║██║██████╔╝██║  ██║███████╗███████╗███████╗\n\
     ╚═╝╚══════╝  ╚═╝     ╚═╝╚═╝╚═╝  ╚══╝╚═╝╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝\n\
OH MY MINISHELL                                                            - ver 1.0\
%s\n", "\033[34m", "\033[37m");
	while (1)
	{
		set_signal();
		init_data(&data, envp);
		data.line = readline("\033[32;1mminishell v1.0 >\033[0m ");
		if (is_line_empty(&data))
			continue ;
		add_history(data.line);
		tokenizer(&data);
		parser(&data);
		executor(&data);
		print_syntax_err(&data);
		clear_data(&data);
	}
	return (0);
}
		// readline returns NULL if EOF is only input
		// print_token_list(&data);
