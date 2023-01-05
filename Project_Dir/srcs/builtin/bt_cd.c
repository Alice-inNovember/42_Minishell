/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:36:05 by tyi               #+#    #+#             */
/*   Updated: 2023/01/05 22:58:30 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"

int	bt_cd(char **cmd_vector, t_list *envp_list)
{
	char	*path;
	char	*new_pwd;
	char	*old_pwd;

	if (check_word_cnt(cmd_vector) == 1 || \
	(check_word_cnt(cmd_vector) == 2 && !ft_strcmp(cmd_vector[1], "~")))
	{
		path = envp_find(envp_list, "HOME");
		if (!path)
		{
			perror("minishell: cd: HOME not set");
			return (EX_BT_FAIL);
		}
	}
	else if (check_word_cnt(cmd_vector) == 2)
		path = cmd_vector[1];
	else
	{
		perror("cd: too many arguments");
		return (EX_BT_FAIL);
	}
	old_pwd = getcwd(0, 0);
	if (chdir(path))
	{
		perror("minishell: cd: Can't change directory");
		return (EX_BT_FAIL);
	}
	new_pwd = getcwd(0, 0);
	envp_add(envp_list, "PWD", new_pwd);
	envp_add(envp_list, "OLDPWD", old_pwd);
	return (EX_SUCCESS);
}

