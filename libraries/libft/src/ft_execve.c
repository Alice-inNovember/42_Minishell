/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:16:19 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/13 13:16:32 by jincpark         ###   ########.fr       */
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
