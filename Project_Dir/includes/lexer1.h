/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:09:11 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/02 14:14:55 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER1_H
# define LEXER1_H

# include "data.h"

typedef struct s_pack
{
	t_list	*token_lst;
	t_list	*envp_lst;
	t_list	buffer_lst;
	char	*line;
	int		index;
}	t_pack;

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

typedef void	(*t_status_fp)(t_status *status, t_pack *pack);

// make_token_list.c
void	make_token_list(t_data *data, char *line);

// make_token_list_utils.c
void	free_pack(t_pack *pack);
void	del_token(void **content);
void	create_token(t_list *token_lst, t_list *buffer_lst, t_type type);

// print_token_lst.c
void	print_token_lst(t_list *token_lst);

// status
void	quote_error(t_status *status, t_pack *pack);
void	dquote_error(t_status *status, t_pack *pack);
void	branch(t_status *status, t_pack *pack);
void	making_word(t_status *status, t_pack *pack);
void	making_pipe(t_status *status, t_pack *pack);
void	making_less(t_status *status, t_pack *pack);
void	making_dless(t_status *status, t_pack *pack);
void	making_great(t_status *status, t_pack *pack);
void	making_dgreat(t_status *status, t_pack *pack);
void	quote_open(t_status *status, t_pack *pack);
void	quote_close(t_status *status, t_pack *pack);
void	dquote_open(t_status *status, t_pack *pack);
void	dquote_close(t_status *status, t_pack *pack);
void	expand(t_status *status, t_pack *pack);
void	dquote_expand(t_status *status, t_pack *pack);

// expand_utils
char	*make_expanded_line(char *line, int index, t_list *envp_lst);
int		is_heredoc_limit_string(t_list *token_lst);
int		get_env_length(char *line);
int		is_proper_env(char *line);

#endif
