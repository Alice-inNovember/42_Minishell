/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:23:08 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/05 17:16:36 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

void	parse_expression(t_data *data, t_list *token_list);
void	syntax_err(t_data *data);
t_list	*sub_token_list(t_node *first, t_node *last);

// heredoc
char	*make_file_using_mktemp(t_data *data, \
										char *mktemp_path, char **mktemp_argv);
char	*make_random_name_file(void);
char	*make_temp_file(t_data *data);

#endif
