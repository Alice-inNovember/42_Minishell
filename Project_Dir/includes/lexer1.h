/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:09:11 by junlee2           #+#    #+#             */
/*   Updated: 2022/12/28 16:11:48 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER1_H
# define LEXER1_H

# include "data.h"

// define lexer status
typedef enum e_status
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
}	t_status;

# define TOTAL_STATUS	12

typedef void	(*t_status_fp)(t_status *status, t_list *token_lst, char **line, t_list *buffer_lst);

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

// tokenize.c
void	tokenize(t_list *token_lst, t_list *envp_lst, char *line);

// tokenize_utils.c
void	del_token(void *content);

// print_token_lst.c
void	print_token_lst(t_list *token_lst);

void	start(t_status *status, t_list *token_lst, char **line, t_list *buffer_lst);
void	make_word(t_status *status, t_list *token_lst, char **line, t_list *buffer_lst);
void	make_pipe(t_status *status, t_list *token_lst, char **line, t_list *buffer_lst);
void	make_less(t_status *status, t_list *token_lst, char **line, t_list *buffer_lst);
void	make_dless(t_status *status, t_list *token_lst, char **line, t_list *buffer_lst);
void	make_great(t_status *status, t_list *token_lst, char **line, t_list *buffer_lst);
void	make_dgreat(t_status *status, t_list *token_lst, char **line, t_list *buffer_lst);
void	quote_open(t_status *status, t_list *token_lst, char **line, t_list *buffer_lst);
void	quote_close(t_status *status, t_list *token_lst, char **line, t_list *buffer_lst);
void	dquote_open(t_status *status, t_list *token_lst, char **line, t_list *buffer_lst);
void	dquote_close(t_status *status, t_list *token_lst, char **line, t_list *buffer_lst);

#endif
