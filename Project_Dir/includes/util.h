/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:44:41 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/11 11:30:15 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "data.h"

void	del_s_token(void *content);
void	del_s_cmd(void *content);
void	del_s_redir(void *content);
void	del_s_proc_data(void *content);
void	del_s_pid(void *content);

void	print_syntax_err(t_data *data);
int		is_line_empty(t_data *data);
int		check_argc(int argc);
void	error_msg(char *target, int errnum);
void	error_handler_for_bt(char *cmd, char *word, int status);

#endif
