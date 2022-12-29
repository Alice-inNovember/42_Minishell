/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:43:30 by jincpark          #+#    #+#             */
/*   Updated: 2022/12/29 19:01:00 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "../libraries/dllist/includes/dllist.h"
# include "lexer2.h"

typedef struct s_envp
{
	char		*key;
	char		*value;
}	t_envp;

typedef struct s_builtin
{
	char		*key;
	void		(*function)(char **, t_list *);
}	t_builtin;

typedef struct s_redir
{
	t_type	type;
	char	*fname;
}	t_redir;

typedef struct s_proc_data
{
	t_list	cmd_lst;
	t_list	redir_lst;
}	t_proc_data;

typedef struct s_data
{
	t_list	token_lst;
	t_list	envp_lst;
	t_list	builtin_lst;
	t_list	proc_data_lst;
	int		syntax_err_flag;
}	t_data;

#endif
