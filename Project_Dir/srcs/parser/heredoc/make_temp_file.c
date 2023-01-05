/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_temp_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:43:14 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/05 17:40:47 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*make_temp_file(t_data *data)
{
	char	*fname;
	char	**mktemp_argv;
	char	*mktemp_path;

	mktemp_argv = ft_split("mktemp", '\0');
	mktemp_path = get_cmd_path(data, mktemp_argv);
	if (mktemp_path != NULL)
		fname = make_file_using_mktemp(data, mktemp_path, mktemp_argv);
	else
		fname = make_random_name_file();
	cmd_argv_free(mktemp_argv);
	free(mktemp_path);
	return (fname);
}
