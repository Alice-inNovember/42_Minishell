/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:17:46 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/11 23:02:10 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLER_H
# define SIGNAL_HANDLER_H

# include <unistd.h>

// signal_handler.c
void	set_signal(void);
void	reset_signal(pid_t pid, int here_flag);
void	print_new_line(int signo);

// signal_utils.c
int		wifsignaled(int status);
int		wtermsig(int status);
int		wexitstatus(int status);

#endif
