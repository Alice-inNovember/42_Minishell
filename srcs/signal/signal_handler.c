/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:54:31 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/13 10:00:23 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "readline/readline.h"
#include "../../includes/data.h"

extern int	g_exit_status;

void	display_new_prompt(int signo)
{
	if (signo == SIGINT)
	{
		g_exit_status = 1;
		rl_replace_line("", 1);
		ft_putendl_fd("", STDOUT_FILENO);
		if (rl_on_new_line() == -1)
			exit (EXIT_FAILURE);
		rl_redisplay();
	}
}

void	child_sig_handler(int signo)
{
	if (signo == SIGINT)
		ft_putendl_fd("", STDERR_FILENO);
	else if (signo == SIGQUIT)
		ft_putendl_fd("Quit: 3", STDOUT_FILENO);
	exit(EX_BY_SIGNAL + signo);
}

void	set_signal(void)
{
	rl_catch_signals = 0;
	signal(SIGINT, display_new_prompt);
	signal(SIGQUIT, SIG_IGN);
}

void	reset_signal(pid_t pid, int here_flag)
{
	rl_catch_signals = 1;
	if (pid == 0)
	{
		signal(SIGINT, child_sig_handler);
		if (here_flag)
			signal(SIGQUIT, SIG_IGN);
		else
			signal(SIGQUIT, child_sig_handler);
	}
	else
		signal(SIGINT, SIG_IGN);
}
