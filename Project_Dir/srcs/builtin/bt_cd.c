/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:36:05 by tyi               #+#    #+#             */
/*   Updated: 2023/01/08 11:20:33 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../includes/builtin.h"
#include "../../includes/envp.h"

int	is_to_home_dir(char **cmd_vector)
{
	if (check_word_cnt(cmd_vector) == 1)
		return (1);
	else if (check_word_cnt(cmd_vector) == 2 && !ft_strcmp(cmd_vector[1], "~"))
		return (1);
	else if (check_word_cnt(cmd_vector) == 2 && getcwd(0, 0) == NULL)
		return (1);
	else
		return (0);
}

int	error_handler_for_cd(char *cmd, char *word, int status)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	if (word)
		ft_putstr_fd(": ", 2);
	ft_putstr_fd(word, 2);
	if (status == HOME_NOT)
		ft_putstr_fd(": HOME not set\n", 2);
	else if (status == CANT_CD)
		ft_putstr_fd(": can't change directory\n", 2);
	else if (status == MANY_ARG)
		ft_putstr_fd(": too many arguments\n", 2);
	return (EX_BT_FAIL);
}

// int	bt_cd(char **cmd_vector, t_list *envp_list)
// {
// 	char	*path;

// 	if (is_to_home_dir(cmd_vector))
// 	{
// 		path = envp_find(envp_list, "HOME");
// 		if (en)
// 	}
// 	else (check_word_cnt > 2)
// 	{
// 	}
// }

int	bt_cd(char **cmd_vector, t_list *envp_list)
{
	char	*path;
	char	*new_pwd;
	char	*old_pwd;

	if (is_to_home_dir(cmd_vector))
	{
		path = envp_find(envp_list, "HOME");
		if (!path)
			return (error_handler_for_cd("cd", 0, HOME_NOT));
	}
	else if (check_word_cnt(cmd_vector) == 2)
		path = cmd_vector[1];
	else
		return (error_handler_for_cd("cd", 0, MANY_ARG));
	old_pwd = getcwd(0, 0);
	printf("path : %s\n old pwd : %s\n", path, old_pwd);
	if (chdir(path))
		return (error_handler_for_cd("cd", path, CANT_CD));
	new_pwd = getcwd(0, 0);
	envp_add(envp_list, "PWD", new_pwd);
	envp_add(envp_list, "OLDPWD", old_pwd);
	return (EX_SUCCESS);
}

// printf ("old : %s\nnew : %s\n", old_pwd, new_pwd);
