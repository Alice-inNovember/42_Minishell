/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_herdoc_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:16:11 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/06 12:41:51 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/data.h"
#include "../../../includes/parser.h"
#include <readline/history.h>
#include <stdio.h>
#include <fcntl.h>

void	get_herdoc_input(char *filename, char *limiter)
{
	int		fd;
	pid_t	pid;
	char	*input_line;

	fd = open(filename, O_WRONLY);
	pid = fork();
	if (pid == 0)
	{
		while (1)
		{
			input_line = readline("> ");

		}

	}
	close(fd);
}
