/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:54:31 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/09 22:06:56 by jincpark         ###   ########.fr       */
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

void	exit_proc(void)
{
	g_last_exit_status = 1;
	exit(1);
}

void	clear_buffer(int signo)
{
	if (signo == SIGINT)
	{
		rl_replace_line("", 1);
		printf("\n");
	}
}

void	set_signal(void)
{
	rl_catch_signals = 0;
	signal(SIGINT, display_new_prompt);
	signal(SIGTERM, exit_proc);
	signal(SIGQUIT, SIG_IGN);
}

void	reset_signal(pid_t pid)
{
	if (pid == 0)
	{
		signal(SIGINT, exit_proc);
		signal(SIGTERM, exit_proc);
		signal(SIGQUIT, SIG_IGN);
	}
	else
	{
		signal(SIGINT, clear_buffer);
		signal(SIGTERM, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
}
