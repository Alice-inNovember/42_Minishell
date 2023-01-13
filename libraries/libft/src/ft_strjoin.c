/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:15:02 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	join(char *joined_str, const char *s1, const char *s2)
{
	while (*s1)
	{
		*joined_str = *s1;
		joined_str++;
		s1++;
	}
	while (*s2)
	{
		*joined_str = *s2;
		joined_str++;
		s2++;
	}
	*joined_str = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	length;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined_str = (char *)ft_calloc(length, sizeof(char));
	join(joined_str, s1, s2);
	return (joined_str);
}
