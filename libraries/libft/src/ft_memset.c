/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:13:36 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 12:07:52 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	character;
	size_t			i;

	ptr = (unsigned char *)b;
	character = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		ptr[i] = character;
		i++;
	}
	return (ptr);
}
