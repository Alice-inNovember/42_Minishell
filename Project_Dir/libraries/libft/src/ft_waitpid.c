/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waitpid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:20:46 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/11 22:22:37 by minseok2         ###   ########.fr       */
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
