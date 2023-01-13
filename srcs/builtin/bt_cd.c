/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:36:05 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../includes/builtin.h"
#include "../../includes/envp.h"

int	is_to_home_dir(char **cmd_vector)
{
	char	*temp;

	if (check_word_cnt(cmd_vector) == 1)
		return (1);
	temp = getcwd(0, 0);
	if (check_word_cnt(cmd_vector) == 2 && temp == NULL)
		return (1);
	else
		return (free(temp), 0);
}

//When  pwd == getcwd(0, 0), pwd == null return (1) and go home

int	error_handler_for_cd(char *cmd, char *word, int status)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	if (word)
		ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(word, STDERR_FILENO);
	if (status == HOME_NOT)
		ft_putstr_fd(": HOME not set\n", STDERR_FILENO);
	else if (status == CANT_CD)
		ft_putstr_fd(": can't change directory\n", STDERR_FILENO);
	else if (status == MANY_ARG)
		ft_putstr_fd(": too many arguments\n", STDERR_FILENO);
	return (EX_BT_FAIL);
}

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
	if (path[0] && chdir(path))
	{
		free (old_pwd);
		return (error_handler_for_cd("cd", path, CANT_CD));
	}
	new_pwd = getcwd(0, 0);
	envp_add(envp_list, "PWD", new_pwd);
	envp_add(envp_list, "OLDPWD", old_pwd);
	(free(old_pwd), free(new_pwd));
	return (EX_SUCCESS);
}
