/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:09:11 by junlee2           #+#    #+#             */
/*   Updated: 2022/12/27 10:12:54 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdio.h>
# include <unistd.h>
# include "readline/readline.h"
# include "readline/history.h"
# include "../libraries/libft/includes/libft.h"
# include "../libraries/get_next_line/includes/get_next_line.h"
# include "../libraries/doubly_linked_list/includes/doubly_linked_list.h"

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
	LEX_FINISH
}	t_lex_status;

# define TOTAL_LEX_STATUS	10

typedef void	(*t_lex_status_fp)(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst);

// define token type as enum
typedef enum e_type
{
	WORD,
	QUOTE_WORD,
	DQUOTE_WORD,
	PIPE,
	LESS,
	GREAT,
	DLESS,
	DGREAT
}	t_type;

typedef enum e_quote_type
{
	NONE,
	SINGLE,
	DOUBLE
}	t_quote_type;

// define token as node
typedef struct s_token
{
	t_type			type;
	t_quote_type	quote_type;
	char			*value;
}	t_token;

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

void	make_token(t_list *token_lst, t_list *buffer_lst, t_type type);
void	lex_start(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst);
void	lex_word(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst);
void	lex_pipe(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst);
void	lex_less(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst);
void	lex_dless(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst);
void	lex_great(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst);
void	lex_dgreat(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst);
void	lex_quote(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst);
void	lex_dquote(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst);

void	make_token_list2(t_data *data, char *line);

#endif
