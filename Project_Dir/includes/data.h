/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:43:30 by jincpark          #+#    #+#             */
/*   Updated: 2022/12/27 15:24:04 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <unistd.h>

// define command as node
typedef struct s_command
{
	char	**cmd_vector;
	t_list	infile_lst;
	t_list	outfile_lst;
}	t_command;

typedef struct s_envp
{
	char		*key;
	char		*value;
}	t_envp;

typedef struct s_data
{
	t_list	token_lst;
	t_list	envp_lst;
	char	**envp;
}	t_data;

typedef struct s_proc_data_lst
{
	pid_t					pid;
	t_command				cmd;
	t_envp					*envp_lst;
	char					**envp;
	struct s_proc_data_lst	*next;
}	t_proc_data_lst;

#endif
