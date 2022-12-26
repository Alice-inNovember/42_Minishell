/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:29:17 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 12:09:57 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*check_needle(const char *hay, const char *ned, size_t len)
{
	size_t	ned_length;
	size_t	checked_length;
	size_t	i;
	size_t	j;

	ned_length = ft_strlen(ned);
	i = 0;
	while (hay[i] && i < len)
	{
		j = 0;
		checked_length = 0;
		while (ned[j] && hay[i + j] == ned[j] && (i + j) < len)
		{
			checked_length++;
			j++;
		}
		if (checked_length == ned_length)
			return ((char *)&hay[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle == '\0')
		return ((char *)haystack);
	return (check_needle(haystack, needle, len));
}
