/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:23:08 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/05 15:16:49 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

void	parser(t_data *data);
void	syntax_err(t_data *data);
t_list	*sub_token_list(t_node *first, t_node *last);

#endif
