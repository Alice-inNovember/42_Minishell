/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:34:38 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/07 18:43:51 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libraries/dllist/includes/dllist.h"
#include "../../includes/util.h"
#include "../../includes/envp.h"
#include "../../includes/builtin.h"

void	init_data(t_data *data, char **envp)
{
	static int	first_call_flag = ON;

	if (first_call_flag == ON)
	{
		envp_init(&data->envp_list, envp);
		builtin_init(&data->builtin_list);
		first_call_flag = OFF;
	}
	list_init(&data->token_list);
	list_init(&data->proc_data_list);
	list_init(&data->pid_list);
	data->syntax_err_flag = 0;
}

void	clear_data(t_data *data)
{
	list_clear(&data->token_list, del_s_token);
	list_clear(&data->proc_data_list, del_s_proc_data);
	list_clear(&data->pid_list, free);
}

int	is_line_empty(char *line)
{
	char	*line_cp;

	line_cp = line;
	while (*line && ((*line >= 9 && *line <= 13) || *line == 32))
		line++;
	if (*line == '\0')
	{
		free(line_cp);
		return (1);
	}
	return (0);
}
