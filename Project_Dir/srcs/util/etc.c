/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:34:38 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/13 19:03:20 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline/readline.h"
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
	data->syntax_err_flag = E_NONE;
}

void	clear_data(t_data *data)
{
	free(data->line);
	list_clear(&data->token_list, del_s_token);
	list_clear(&data->proc_data_list, del_s_proc_data);
	list_clear(&data->pid_list, free);
	data->syntax_err_flag = E_NONE;
}

void	check_eof(char *line)
{
	if (line == NULL)
	{
		ft_putendl_fd("exit", STDOUT_FILENO);
		exit (EXIT_SUCCESS);
	}
}

void	check_argc(int argc)
{
	if (argc > 1)
	{
		ft_putendl_fd("minishell: \
Our minishell doesn't support this mode\
		", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
