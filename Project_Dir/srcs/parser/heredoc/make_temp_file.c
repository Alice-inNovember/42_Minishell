/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_temp_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:43:14 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/11 17:27:19 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"
#include "../../../includes/executor.h"

char	*make_temp_file(t_data *data)
{
	char	*filename;
	char	**mktemp_argv;
	char	*mktemp_path;

	mktemp_argv = ft_split("mktemp", '\0');
	mktemp_path = get_cmd_path(data, mktemp_argv);
	filename = make_file_using_mktemp(data, mktemp_path, mktemp_argv);
	if (filename == NULL)
		filename = make_random_name_file();
	ft_free_vector(mktemp_argv);
	free(mktemp_path);
	return (filename);
}
