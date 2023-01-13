/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_limiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:50:56 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/13 12:27:17 by jincpark         ###   ########.fr       */
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
