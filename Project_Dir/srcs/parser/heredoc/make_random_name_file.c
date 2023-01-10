/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_random_name_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:05:59 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/10 16:17:24 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*make_random_name(int urandom_fd)
{
	const char		*charset = "abcdefghijklmnopqrstuvwxyz0123456789";
	char			*filename;
	unsigned int	buf[8];
	char			concat_str[9];
	int				i;

	ft_memset(concat_str, 0, sizeof(concat_str));
	while (1)
	{
		read(urandom_fd, buf, 8);
		i = 0;
		while (i < 8)
		{
			concat_str[i] = charset[buf[i] % 36];
			i++;
		}
		filename = ft_strjoin("tmp.", concat_str);
		if (access(filename, F_OK) != 0)
		{
			close(urandom_fd);
			return (filename);
		}
		free(filename);
	}
}

char	*make_random_name_file(void)
{
	char	*filename;
	int		urandom_fd;
	int		temp_file_fd;

	urandom_fd = open("/dev/urandom", O_RDONLY);
	filename = make_random_name(urandom_fd);
	close(urandom_fd);
	temp_file_fd = open(filename, O_WRONLY | O_CREAT, 0644);
	close(temp_file_fd);
	return (filename);
}
