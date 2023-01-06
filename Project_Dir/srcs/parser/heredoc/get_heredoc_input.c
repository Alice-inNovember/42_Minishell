/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:16:11 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/07 08:02:52 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/data.h"
#include "../../../includes/parser.h"
#include <readline/readline.h>
#include <fcntl.h>
#include <stdlib.h>

void	get_heredoc_input(char *filename, char *limiter)
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
			if (ft_strcmp(input_line, limiter) == 0)
			{
				free(input_line);
				break ;
			}
			ft_putendl_fd(input_line, fd);
			free(input_line);
		}
		exit(EXIT_SUCCESS);
	}
	close(fd);
}
