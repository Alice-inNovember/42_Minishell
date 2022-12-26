/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:30:32 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 12:02:23 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_bzero(void *ptr, size_t count)
{
	unsigned char	*init_ptr;
	size_t			i;

	i = 0;
	init_ptr = (unsigned char *)ptr;
	while (i < count)
	{
		init_ptr[i] = 0;
		i++;
	}
}
