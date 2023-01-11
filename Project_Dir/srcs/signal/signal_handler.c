/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:54:31 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/11 21:00:19 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include "readline/readline.h"
#include "../../includes/data.h"

extern int	g_exit_status;

void	display_new_prompt(int signo)
{
	if (signo == SIGINT)
	{
		g_exit_status = 1;
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
		ft_putendl_fd("", STDERR_FILENO);
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

void	reset_signal_before_fork(pid_t pid)
{
	rl_catch_signals = 1;
	if (pid == 0)
	{
		signal(SIGINT, exit_proc);
		signal(SIGQUIT, exit_proc);
	}
	else
		signal(SIGINT, SIG_IGN);
}
