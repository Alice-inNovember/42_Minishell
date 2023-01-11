/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:34:32 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/11 11:17:31 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t data_type_size)
{
	void	*ptr;

	ptr = malloc(count * data_type_size);
	if (ptr == NULL)
		ft_exit("malloc assertion failure", STDERR_FILENO, EXIT_FAILURE);
	ft_bzero(ptr, (count * data_type_size));
	return (ptr);
}
