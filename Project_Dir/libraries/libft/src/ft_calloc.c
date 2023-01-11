/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:34:32 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/11 12:35:34 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t data_type_size)
{
	void	*ptr;

	ptr = malloc(count * data_type_size);
	if (ptr == NULL)
	{
		perror("malloc error occurred");
		exit(EXIT_FAILURE);
	}
	ft_bzero(ptr, (count * data_type_size));
	return (ptr);
}
