/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:43:30 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/04 13:01:01 by junlee2          ###   ########seoul.kr  */
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

//define syntax error type
typedef enum e_error
{
	E_NONE,
	E_SINGLE_QUOTE,
	E_SINGLE_DQUOTE,
	E_NEAR_PIPE,
	E_NEAR_GREAT,
	E_NEAR_DGREAT,
	E_NEAR_LESS,
	E_NEAR_DLESS,
	E_NEAR_NEWLINE
}	t_error;

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

// define exit code type as enum
typedef enum e_excode
{
	EX_SUCCESS = 0,
	EX_FAILURE = 1,
	EX_BT_FAIL = 2,
	EX_CNOT_EXEC = 126,
	EX_CNOT_FIND = 127,
	EX_BY_SIGNAL = 128
}	t_excode;
// 0		성공
// 1		일반적인 에러
// 2		builtin shell command 에러
// 126		command가 존재하지만 실행 불가
// 127		command 존재 x
// 128		not used on shell
// 128+N	signal N 으로 종료된 경우
// 255		범위 밖인 경우

// define token as node
typedef struct s_token
{
	t_type			type;
	char			*value;
}	t_token;

typedef struct s_builtin
{
	char	*key;
	int		(*function)(char **, t_list *);
}	t_builtin;

typedef struct s_redir
{
	t_type	type;
	char	*fname;
}	t_redir;

typedef struct s_proc_data
{
	t_list	cmd_list;
	t_list	redir_list;
}	t_proc_data;

typedef struct s_data
{
	char	*line;
	t_list	envp_list;
	t_list	token_list;
	t_list	builtin_list;
	t_list	proc_data_list;
	t_list	pid_list;
	t_error	syntax_err_flag;
}	t_data;

#endif
