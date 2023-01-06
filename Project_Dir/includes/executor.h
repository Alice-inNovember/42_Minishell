/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:00:46 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/06 18:58:48 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "data.h"

void	executor(t_data *data);
void	execute_child(t_data *data, t_proc_data *proc, int w_end, int r_end);
char	**cmd_list2arr(t_list *cmd_list);
char	**get_path(t_data *data);
char	*get_cmd_path(t_data *data, char **cmd_argv);
void	child_redirect(t_proc_data *proc_data, int w_end, int r_end);
int		open_redirect(t_redir *redir_data);
void	cmd_argv_free(char **cmd_argv);
int		wexitstatus(int status);
void	pid_list_add(t_list *pidlist, pid_t pid);
void	do_redirect(t_proc_data *proc_data);
int		is_last_cmd(t_data *data, t_proc_data *proc_data);
int		is_first_cmd(t_data *data, t_proc_data *proc_data);

#endif
