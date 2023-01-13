/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:51:02 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "data.h"

# define TOTAL_STATE	41

typedef enum e_state
{
	START,
	BRANCH,
	SKIP_SPACE,
	ADD_BUF_PIPE,
	MAKE_PIPE_TOKEN,
	ADD_BUF_LESS,
	BRANCH_LESS,
	MAKE_LESS_TOKEN,
	ADD_BUF_DLESS,
	MAKE_DLESS_TOKEN,
	ADD_BUF_GREAT,
	BRANCH_GREAT,
	MAKE_GREAT_TOKEN,
	ADD_BUF_DGREAT,
	MAKE_DGREAT_TOKEN,
	ADD_BUF_WORD,
	MAKE_WORD_TOKEN,
	CHECK_EXPAND,
	EXPAND,
	QUESTION_MARK_EXPAND,
	BRANCH_EXPAND,
	SKIP_SPACE_IN_EXPAND,
	ADD_BUF_IN_EXPAND,
	MAKE_WORD_TOKEN_EXPAND,
	EXPAND_END,
	OPEN_QUOTE,
	BRANCH_QUOTE,
	OPEN_QUOTE_ERROR,
	ADD_BUF_IN_QUOTE,
	CLOSE_QUOTE,
	OPEN_DQUOTE,
	BRANCH_DQUOTE,
	SKIP_BACKSLASH_IN_DQUOTE,
	OPEN_DQUOTE_ERROR,
	ADD_BUF_IN_DQUOTE,
	CHECK_EXPAND_DQUOTE,
	EXPAND_DQUOTE,
	QUESTION_MARK_EXPAND_DQUOTE,
	CLOSE_DQUOTE,
	CLEAR,
	FINISH
}	t_state;

typedef struct s_asset
{
	char	*line;
	int		index;
	t_list	*envp_list;
	t_list	*token_list;
	t_list	buf_list;
	t_error	*syntax_err_flag;
}	t_asset;

typedef void	(*t_state_fp)(t_state *state, t_asset *asset);

// tokenizer
void	tokenizer(t_data *data);

// utils
char	*make_buf(char input);
char	*join_buf(t_list *buf_list);

// utils - expand
int		get_env_length(char *line);
int		is_limiter(t_list *token_list);
char	*make_expanded_line(t_asset *asset);
char	*make_question_mark_expanded_line(t_asset *asset);

// state
void	start(t_state *state, t_asset *asset);
void	branch(t_state *state, t_asset *asset);
void	skip_space(t_state *state, t_asset *asset);
void	clear(t_state *state, t_asset *asset);

// state - pipe
void	add_buf_pipe(t_state *state, t_asset *asset);
void	make_pipe_token(t_state *state, t_asset *asset);

// state - less
void	add_buf_less(t_state *state, t_asset *asset);
void	branch_less(t_state *state, t_asset *asset);
void	make_less_token(t_state *state, t_asset *asset);
void	add_buf_dless(t_state *state, t_asset *asset);
void	make_dless_token(t_state *state, t_asset *asset);

// state - great
void	add_buf_great(t_state *state, t_asset *asset);
void	branch_great(t_state *state, t_asset *asset);
void	make_great_token(t_state *state, t_asset *asset);
void	add_buf_dgreat(t_state *state, t_asset *asset);
void	make_dgreat_token(t_state *state, t_asset *asset);

// state - word
void	add_buf_word(t_state *state, t_asset *asset);
void	make_word_token(t_state *state, t_asset *asset);

// state - expand
void	check_expand(t_state *state, t_asset *asset);
void	expand(t_state *state, t_asset *asset);
void	question_mark_expand(t_state *state, t_asset *asset);
void	branch_expand(t_state *state, t_asset *asset);
void	skip_space_in_expand(t_state *state, t_asset *asset);
void	add_buf_in_expand(t_state *state, t_asset *asset);
void	make_word_token_expand(t_state *state, t_asset *asset);
void	expand_end(t_state *state, t_asset *asset);

// state - quote
void	open_quote(t_state *state, t_asset *asset);
void	branch_quote(t_state *state, t_asset *asset);
void	open_quote_error(t_state *state, t_asset *asset);
void	add_buf_in_quote(t_state *state, t_asset *asset);
void	close_quote(t_state *state, t_asset *asset);

// state - dquote
void	open_dquote(t_state *state, t_asset *asset);
void	branch_dquote(t_state *state, t_asset *asset);
void	skip_backslash_in_dquote(t_state *state, t_asset *asset);
void	open_dquote_error(t_state *state, t_asset *asset);
void	add_buf_in_dquote(t_state *state, t_asset *asset);
void	close_dquote(t_state *state, t_asset *asset);

// state - dquote - expand
void	check_expand_dquote(t_state *state, t_asset *asset);
void	expand_dquote(t_state *state, t_asset *asset);
void	question_mark_expand_dquote(t_state *state, t_asset *asset);

#endif
