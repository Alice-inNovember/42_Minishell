/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:09:11 by junlee2           #+#    #+#             */
/*   Updated: 2022/12/30 14:29:54 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER1_H
# define LEXER1_H

# include "data.h"

// tokenize.c
void	tokenize(t_data *data, char *line);

// tokenize_utils.c
void	del_token(void *content);
void	create_token(t_list *token_lst, t_list *buffer_lst, t_type type);

// print_token_lst.c
void	print_token_lst(t_list *token_lst);

// status
void	quote_error(t_status *status, t_data *data, char **line, t_list *buffer_lst);
void	dquote_error(t_status *status, t_data *data, char **line, t_list *buffer_lst);
void	branch(t_status *status, t_data *data, char **line, t_list *buffer_lst);
void	making_word(t_status *status, t_data *data, char **line, t_list *buffer_lst);
void	making_pipe(t_status *status, t_data *data, char **line, t_list *buffer_lst);
void	making_less(t_status *status, t_data *data, char **line, t_list *buffer_lst);
void	making_dless(t_status *status, t_data *data, char **line, t_list *buffer_lst);
void	making_great(t_status *status, t_data *data, char **line, t_list *buffer_lst);
void	making_dgreat(t_status *status, t_data *data, char **line, t_list *buffer_lst);
void	quote_open(t_status *status, t_data *data, char **line, t_list *buffer_lst);
void	quote_close(t_status *status, t_data *data, char **line, t_list *buffer_lst);
void	dquote_open(t_status *status, t_data *data, char **line, t_list *buffer_lst);
void	dquote_close(t_status *status, t_data *data, char **line, t_list *buffer_lst);
void	expand(t_status *status, t_data *data, char **line, t_list *buffer_lst);
void	dquote_expand(t_status *status, t_data *data, char **line, t_list *buffer_lst);

// expand_utils
char	*make_expanded_line(char *line, t_list *envp_lst);
int		is_heredoc_limit_string(t_list *token_lst);
int		get_env_length(char *line);
int		is_proper_env(char *line);

#endif
