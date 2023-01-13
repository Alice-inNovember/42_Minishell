/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:58:01 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			length;

	if (s == NULL)
		return (NULL);
	length = ft_strlen(s);
	if (s == NULL || length < start || length == 0)
		return (ft_strdup(""));
	if (len > length)
		substr = (char *)ft_calloc((length + 1), sizeof(char));
	else
		substr = (char *)ft_calloc((len + 1), sizeof(char));
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
