/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:43:30 by jincpark          #+#    #+#             */
/*   Updated: 2022/12/30 14:22:54 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "../libraries/dllist/includes/dllist.h"

typedef struct s_envp
{
	char		*key;
	char		*value;
}	t_envp;

// define lexer status
typedef enum e_status
{
	BRANCH,
	MAKING_WORD,
	MAKING_PIPE,
	MAKING_LESS,
	MAKING_DLESS,
	MAKING_GREAT,
	MAKING_DGREAT,
	QUOTE_OPEN,
	QUOTE_CLOSE,
	DQUOTE_OPEN,
	DQUOTE_CLOSE,
	EXPAND,
	DQUOTE_EXPAND,
	QUOTE_ERROR,
	DQUOTE_ERROR,
	FINISH
}	t_status;

# define TOTAL_STATUS	17

// define token type as enum
typedef enum e_type
{
	T_WORD,
	T_PIPE,
	T_LESS,
	T_GREAT,
	T_DLESS,
	T_DGREAT
}	t_type;

// define token as node
typedef struct s_token
{
	t_type			type;
	char			*value;
}	t_token;

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
	char	*line;
	t_list	token_lst;
	t_list	envp_lst;
	t_list	builtin_lst;
	t_list	proc_data_lst;
	int		syntax_err_flag;
}	t_data;

typedef void	(*t_status_fp)(t_status *status, \
		t_data *data, char **line, t_list *buffer_lst);

#endif
