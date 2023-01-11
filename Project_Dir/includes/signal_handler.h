/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:17:46 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/11 21:48:26 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLER_H
# define SIGNAL_HANDLER_H

# include <unistd.h>

void	set_signal(void);
void	reset_signal(pid_t pid, int here_flag);
void	print_new_line(int signo);

// signal_utils
int		wifsignaled(int status);
int		wtermsig(int status);
int		wexitstatus(int status);

#endif
