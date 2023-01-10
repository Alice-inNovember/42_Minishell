/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:00:46 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/10 16:27:33 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "data.h"

void	executor(t_data *data);
void	execute_child(t_data *data, t_proc_data *proc, int pip[2][2], int *ofd);
char	**cmd_list2arr(t_list *cmd_list);
char	**get_path_envp(t_data *data);
char	*get_cmd_path(t_data *data, char **cmd_argv);
void	child_redirect(t_proc_data *proc_data, int w_end, int r_end);
int		open_redirect(t_redir *redir_data);
int		wexitstatus(int status);
void	pid_list_add(t_list *pidlist, pid_t pid);
int		do_redirect(t_proc_data *proc_data);
int		is_last_cmd(t_data *data, t_proc_data *proc_data);
int		is_first_cmd(t_data *data, t_proc_data *proc_data);

#endif
