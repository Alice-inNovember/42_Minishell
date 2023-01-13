/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:35:01 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/11 22:58:09 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_stat(const char *path, struct stat *buf)
{
	int	ret;

	ret = stat(path, buf);
	if (ret == -1)
	{
		perror("stat error occurred");
		exit(EXIT_FAILURE);
	}
	return (ret);
}
