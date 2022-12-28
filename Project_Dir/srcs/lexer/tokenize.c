/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:37:25 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/28 10:47:05 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/lexer1.h"

void	del_token(void *content)
{
	t_token	*token;

	token = content;
	ft_free(token->value);
}

void	tokenize(t_list *token_lst, char *line)
{
	lst_init(token_lst);
	lst_clear(token_lst, del_token);
}
