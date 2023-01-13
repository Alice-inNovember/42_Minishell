/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:58:01 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 12:17:56 by minseok2         ###   ########.fr       */
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
