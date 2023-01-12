/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:27:31 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/11 22:31:06 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_execve(const char *path, char *const argv[], char *const envp[])
{
	int	ret;

	ret = execve(path, argv, envp);
	if (ret == -1)
	{
		perror("execve error occurred");
		exit(EXIT_FAILURE);
	}
	return (ret);
}
