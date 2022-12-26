/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:01:09 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 12:07:46 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = -1;
	if (dest < source)
	{
		while (++i < len)
			dest[i] = source[i];
	}
	else
	{
		while (len > 0)
		{
			dest[len - 1] = source[len - 1];
			len--;
		}
	}
	return (dest);
}
