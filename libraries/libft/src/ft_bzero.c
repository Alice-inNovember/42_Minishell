/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:28:26 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:41:52 by tyi              ###   ########.fr       */
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
