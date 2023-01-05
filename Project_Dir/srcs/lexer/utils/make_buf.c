/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_buf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:42:39 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/05 10:42:43 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/lexer.h"

void	del_buffer(void *content)
{
	free(content);
}

char	*make_buf(char input)
{
	char	*buf;

	buf = (char *)ft_calloc(1, sizeof(char));
	*buf = input;
	return (buf);
}
