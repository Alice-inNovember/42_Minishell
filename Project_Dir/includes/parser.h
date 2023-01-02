/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:23:08 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/02 22:19:29 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

void	parse_expression(t_data *data, t_list *token_lst);
void	syntax_err(t_data *data);
t_list	*sub_token_lst(t_data *data, t_node *first, t_node *last);

#endif
