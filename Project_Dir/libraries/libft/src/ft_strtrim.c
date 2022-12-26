/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:59:43 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 12:10:11 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	is_in_set(char input, const char *set)
{
	while (*set)
	{
		if (input == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_str;
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (start < ft_strlen(s1) && is_in_set(s1[start], set))
		start++;
	while (end >= 0 && is_in_set(s1[end], set))
	{
		if (end == 0)
			break ;
		end--;
	}
	if (start > end)
		return (ft_strdup(""));
	trimmed_str = ft_substr(s1, start, end - start + 1);
	return (trimmed_str);
}
