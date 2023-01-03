/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:00:46 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/03 15:16:43 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "data.h"

void	execute_child(t_data *data, t_proc_data *proc, int *pip, int read_end);
char	**cmd_list2arr(t_list *cmd_list);
char	**get_path(t_data *data);
char	*get_cmd_path(t_data *data, char **cmd_argv);

#endif