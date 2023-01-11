/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:06:27 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/11 22:07:44 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_dup(int fildes)
{
	int	ret;

	ret = dup(fildes);
	if (ret == -1)
	{
		perror("dup error occurred");
		exit(EXIT_FAILURE);
	}
	return (ret);
}
