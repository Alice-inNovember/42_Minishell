/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waitpid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:20:46 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

pid_t	ft_waitpid(pid_t pid, int *stat_loc, int options)
{
	pid_t	ret;

	ret = waitpid(pid, stat_loc, options);
	if (ret == -1)
	{
		perror("waitpid error occurred");
		exit(EXIT_FAILURE);
	}
	return (ret);
}
