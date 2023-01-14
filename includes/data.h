/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:43:30 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/14 17:37:15 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "../libraries/dllist/includes/dllist.h"

// define on, off
# define OFF	0
# define ON		1

// define pipe end
# define READ_END	0
# define WRITE_END	1

// define pipe
# define NOW	0
# define PREV	1

// define unused type
typedef void	t_unused;

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
	E_NEAR_NEWLINE,
	E_SIGINT
}	t_error;

typedef enum e_errnum
{
	EN_CNOT_FIND,
	EN_PER_DENIED,
	EN_IS_DIR,
	EN_FNOT_FIND
}	t_errnum;

// define exit code type
typedef enum e_excode
{
	EX_SUCCESS = 0,
	EX_FAILURE = 1,
	EX_BT_FAIL = 2,
	EX_CNOT_EXEC = 126,
	EX_CNOT_FIND = 127,
	EX_BY_SIGNAL = 128,
	EX_OUTOF_RANGE = 255
}	t_excode;

/*
 * <exit code>
 * 0       => Success
 * 1       => General Error
 * 2       => Built-in Shell Command Error
 * 126     => Command is found but is not Executable
 * 127     => Command not found
 * 128     => not used on shell
 * 128 + N => exit by signal N
 * 255     => Out of Range
 */

// define envp node
typedef struct s_envp
{
	char		*key;
	char		*value;
}	t_envp;

// define token type
typedef enum e_type
{
	T_WORD,
	T_PIPE,
	T_LESS,
	T_GREAT,
	T_DLESS,
	T_DGREAT
}	t_type;

// define token node
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
	char	*filename;
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

void	init_data(t_data *data, char **envp);
void	clear_data(t_data *data);

#endif
