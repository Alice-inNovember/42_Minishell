/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:09:11 by junlee2           #+#    #+#             */
/*   Updated: 2022/12/29 19:20:58 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER2_H
# define LEXER2_H

# include <unistd.h>
# include "data.h"

// define token type as enum
//typedef enum e_type
//{
//	T_WORD,
//	T_QUOTE_WORD,
//	T_DQUOTE_WORD,
//	T_PIPE,
//	T_LESS,
//	T_GREAT,
//	T_DLESS,
//	T_DGREAT
//}	t_type;
//
//// define token as node
//typedef struct s_token
//{
//	t_type			type;
//	char			*value;
//}	t_token;

void	make_token(t_list *token_lst, t_list *buffer_lst, t_type type);
void	make_token_list2(t_data *data, char *line);

#endif
