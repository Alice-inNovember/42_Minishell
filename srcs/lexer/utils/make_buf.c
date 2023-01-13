/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_buf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:06:22 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/08 18:07:22 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/lexer.h"

char	*make_buf(char input)
{
	char	*buf;

	buf = (char *)ft_calloc(1, sizeof(char));
	*buf = input;
	return (buf);
}
