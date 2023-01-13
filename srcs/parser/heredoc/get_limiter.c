/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_limiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:50:56 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/09 09:38:44 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/data.h"
#include "../../../includes/parser.h"

char	*get_limiter(t_list *token_list)
{
	t_token	*last_token;
	char	*limiter;

	last_token = list_peek_last_content(token_list);
	limiter = last_token->value;
	return (limiter);
}
