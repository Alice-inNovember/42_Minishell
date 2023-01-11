/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:34:38 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/11 11:32:31 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../libraries/dllist/includes/dllist.h"
#include "../../includes/util.h"
#include "../../includes/envp.h"
#include "../../includes/builtin.h"

extern int		g_last_exit_status;

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
	free(data->line);
	list_clear(&data->token_list, del_s_token);
	list_clear(&data->proc_data_list, del_s_proc_data);
	list_clear(&data->pid_list, free);
}

int	is_line_empty(t_data *data)
{
	char	*line_cp;

	if (data->line == NULL)
		exit (g_last_exit_status);
	line_cp = data->line;
	while (*line_cp && ((*line_cp >= 9 && *line_cp <= 13) || *line_cp == 32))
		line_cp++;
	if (*line_cp == '\0')
	{
		clear_data(data);
		return (1);
	}
	return (0);
}

int	check_argc(int argc)
{
	if (argc > 1)
	{
		ft_putendl_fd("minishell: \
		Our minishell doesn't support this mode\
		", STDERR_FILENO);
		return (0);
	}
	return (1);
}
