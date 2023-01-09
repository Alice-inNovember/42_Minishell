/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:13:42 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/09 21:57:24 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	(void) argv;
	if (!check_argc(argc))
		return (1);
	while (1)
	{
		set_signal();
		init_data(&data, envp);
		// readline returns NULL if EOF is only input
		data.line = readline("minishell> ");
		if (is_line_empty(&data))
			continue ;
		add_history(data.line);
		tokenizer(&data);
		// print_token_list(&data);
		parser(&data);
		executor(&data);
		print_syntax_err(&data);
		clear_data(&data);
	}
	return (0);
}
