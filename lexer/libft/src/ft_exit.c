/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:50:51 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 11:52:07 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_exit(const char *signal, int fd, int status)
{
	if (signal != NULL)
		ft_putendl_fd((char *)signal, fd);
	exit (status);
}
