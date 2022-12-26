/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:43:30 by jincpark          #+#    #+#             */
/*   Updated: 2022/12/26 15:02:19 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <unistd.h>

typedef struct s_envp_lst
{
	char		*key;
	char		*value;
	t_envp_lst	*next;
}	t_envp_lst;

typedef struct s_proc_data_lst
{
	pid_t			pid;
	t_command		cmd;
	t_envp			*envp_lst;
	char			**envp;
	//...
	t_proc_data_lst	*next;
}	t_proc_data_lst;

typedef struct s_data
{
	t_proc_data_lst	*proc_data_lst;
	t_envp			*envp_lst;
	char			**envp;
}	t_data;

#endif
