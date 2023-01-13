/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:23:08 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/13 12:37:53 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "data.h"

void		parser(t_data *data);
void		parse_cmd_prefix(t_data *data, \
							t_proc_data *proc_data, t_list *token_list);
void		parse_cmd_suffix(t_data *data, \
							t_proc_data *proc_data, t_list *token_list);
void		parse_redirect(t_data *data, \
							t_proc_data *proc_data, t_list *token_list);
void		parse_io_here(t_data *data, \
							t_proc_data *proc_data, t_list *token_list);
void		parse_cmd_word(t_data *data, \
							t_proc_data *proc_data, t_list *token_list);

int			is_return_case(t_data *data, t_list *token_list, t_error flag);
int			is_redir(t_type type);
int			is_redir_form(t_data *data, t_node *node);

void		set_redir_err_flag(t_data *data, t_token *token);
void		set_s_redir(t_redir *redir, t_type type, char *filename);

t_list		*sub_token_list(t_node *first, t_node *last);
t_proc_data	*new_proc_data(void);
t_node		*get_cmd_node(t_data *data, t_list *token_list);
t_token		*get_token(t_node *node);
void		clear_and_free_token_list(t_list *list);

// heredoc
char		*make_temp_file(t_data *data);
char		*make_file_using_mktemp(t_data *data, \
										char *mktemp_path, char **mktemp_argv);
char		*make_random_name_file(void);
int			get_heredoc_input(char *filename, char *limiter);
char		*get_limiter(t_list *token_list);

#endif
