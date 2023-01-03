/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:37:32 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/03 13:12:46 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "data.h"

// define unused type
typedef void	t_unused;

// define state
typedef enum e_state
{
	INIT,
	BRANCH,
	MAKING_WORD,
	MAKING_PIPE,
	MAKING_LESS,
	MAKING_DLESS,
	MAKING_GREAT,
	MAKING_DGREAT,
	QUOTE_OPEN,
	QUOTE_CLOSE,
	DQUOOTE_OPEN,
	DQUOTE_CLOSE,
	FINISH
}	t_state;

// define total state
# define TOTAL_STATE	13

// define state function pointer
typedef void	(*t_state_fp)(t_state *state, \
								t_data *data, t_list *buf_list, int *idx);

void	make_token_list(t_data *data);

// state functions
void	init(t_state *state, t_data *data, t_list *buf_list, int *idx);
void	branch(t_state *state, t_data *data, t_list *buf_list, int *idx);
void	making_word(t_state *state, t_data *data, t_list *buf_list, int *idx);
void	making_pipe(t_state *state, t_data *data, t_list *buf_list, int *idx);
void	making_less(t_state *state, t_data *data, t_list *buf_list, int *idx);
void	making_dless(t_state *state, t_data *data, t_list *buf_list, int *idx);
void	making_great(t_state *state, t_data *data, t_list *buf_list, int *idx);
void	making_dgreat(t_state *state, t_data *data, t_list *buf_list, int *idx);
void	quote_open(t_state *state, t_data *data, t_list *buf_list, int *idx);
void	quote_close(t_state *state, t_data *data, t_list *buf_list, int *idx);
void	dquote_open(t_state *state, t_data *data, t_list *buf_list, int *idx);
void	dquote_close(t_state *state, t_data *data, t_list *buf_list, int *idx);

// expand functions

#endif
