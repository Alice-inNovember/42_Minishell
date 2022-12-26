/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:09:11 by junlee2           #+#    #+#             */
/*   Updated: 2022/12/26 14:25:38 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdio.h>
# include <unistd.h>
# include "readline/readline.h"
# include "readline/history.h"
# include "../get_next_line/includes/get_next_line.h"
# include "../doubly_linked_list/includes/doubly_linked_list.h"

// define lexer status
typedef enum e_lex_status
{
	LEX_START,
	LEX_WORD,
	LEX_PIPE,
	LEX_LESS,
	LEX_GREAT,
	LEX_DLESS,
	LEX_DGREAT,
	LEX_QUOTE,
	LEX_DQUOTE,
	LEX_MAKE_TOKEN,
	LEX_FINISH
}	t_lex_status;

# define TOTAL_LEX_STATUS	11

typedef void	(*t_lex_status_fp)(char **line, char **buffer);

// define token type as enum
typedef enum e_type
{
	WORD,
	PIPE,
	REDIRECT
}	t_type;

// define token as node
typedef struct s_token
{
	t_type	type;
	char	*value;
}	t_token;

// define redirect as enum
typedef enum e_redirect
{
	LESS,
	GREAT,
	DLESS,
	DGREAT
}	t_redirect;

// define command as node
typedef struct s_command
{
	char	**cmd_vector;
	t_list	infile_lst;
	t_list	outfile_lst;
}	t_command;

typedef struct s_data
{
	t_list	token_lst;
}	t_data;

void	lex_start(char **line, char **buffer);
void	lex_word(char **line, char **buffer);
void	lex_pipe(char **line, char **buffer);
void	lex_less(char **line, char **buffer);
void	lex_dless(char **line, char **buffer);
void	lex_great(char **line, char **buffer);
void	lex_dgreat(char **line, char **buffer);
void	lex_quote(char **line, char **buffer);
void	lex_dquote(char **line, char **buffer);
void	lex_make_token(char **line, char **buffer);
void	lex_finish(char **line, char **buffer);

#endif