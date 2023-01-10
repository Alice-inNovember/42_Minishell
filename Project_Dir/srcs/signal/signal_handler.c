/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:54:31 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/10 23:03:18 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include "readline/readline.h"
#include "../../includes/data.h"

extern int	g_last_exit_status;

void	display_new_prompt(int signo)
{
	if (signo == SIGINT)
	{
		g_last_exit_status = 1;
		rl_replace_line("", 1);
		printf("\n");
		if (rl_on_new_line() == -1)
			exit (EXIT_FAILURE);
		rl_redisplay();
	}
}

void	exit_proc(int signo)
{
	if (signo == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		exit(EX_BY_SIGNAL);
	}
}

void	print_new_line(int signo)
{
	if (signo == SIGINT)
		printf("\n");
}

void	set_signal(void)
{
	rl_catch_signals = 0;
	signal(SIGINT, display_new_prompt);
	signal(SIGQUIT, SIG_IGN);
}

void	reset_signal(pid_t pid, int here_flag)
{
	if (pid == 0)
	{
		rl_catch_signals = 1;
		signal(SIGINT, exit_proc);
	}
	else
	{
		if (here_flag)
			signal(SIGINT, SIG_IGN);
		else
			signal(SIGINT, print_new_line);
	}
}
