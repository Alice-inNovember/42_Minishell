/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:09:11 by junlee2           #+#    #+#             */
/*   Updated: 2022/12/27 15:17:17 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER1_H
# define LEXER1_H

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
	START,
	MAKE_WORD,
	MAKE_PIPE,
	MAKE_LESS,
	MAKE_DLESS,
	MAKE_GREAT,
	MAKE_DGREAT,
	QUOTE_OPEN,
	QUOTE_CLOSE,
	DQUOTE_OPEN,
	DQUOTE_CLOSE,
	FINISH
}	t_lex_status;

# define TOTAL_LEX_STATUS	12

typedef void	(*t_lex_status_fp)(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst);

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
void	start(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst);
void	make_word(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst);
void	make_pipe(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst);
void	make_less(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst);
void	make_dless(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst);
void	make_great(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst);
void	make_dgreat(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst);
void	quote_open(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst);
void	quote_close(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst);
void	dquote_open(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst);
void	dquote_close(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst);

#endif
