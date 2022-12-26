/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:39:23 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 12:10:05 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*memo_s;
	int		key;

	key = 0;
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if (*s == (char)c)
		{
			memo_s = (char *)s;
			key = 1;
		}
		s++;
	}
	if (key == 1)
		return (memo_s);
	return (NULL);
}
