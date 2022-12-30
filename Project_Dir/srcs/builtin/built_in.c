/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:06:49 by tyi               #+#    #+#             */
/*   Updated: 2022/12/30 14:14:00 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../Project_Dir/includes/minishell.h>
# include <sys/types.h>
# include <dirent.h>
# include "../libraries/dllist/includes/dllist.h"


void	bt_echo(char **cmd_vector, t_list *envp_list)
{
	int	i;
	char	*word;
	int	new_line_flag;

	new_line_flag = 1;
	i = 1;
	while (cmd_vector[i][0] == '-' && cmd_vector[i][0] == 'n')
	{
		new_line_flag = 0;
		i++;
	}
	while (cmd_vector[i])
	{
		word = cmd_vector[i];
		ft_printf("%s", cmd_vector[i]);
		i++;
	}
	if (new_line_flag == 1)
		ft_printf("\n");
}

void	bt_pwd(char **cmd_vector,t_list *envp_list)
{
	char	*pwd;
	
	pwd = envp_find(envp_find, "PWD");
	ft_printf("%s\n", pwd);
}

void	bt_env(char **cmd_vector,t_list *envp_list)
{
	t_node	*cur_node;
	char	*key;
	char	*value;

	cur_node = lst_peek_first(envp_list);
	while (cur_node != lst_peek_last(envp_list))
	{
		key = cur_node->content->key;
		value = cur_node->content->value;
		ft_printf("%s=%s\n", key, value);
	}
}

void	bt_exit(char **cmd_vector,t_list *envp_list)
{

}

void	bt_cd(char **cmd_vector, t_list *envp_list)
{
	char	*path;
	char	*new_pwd;
	char	*old_pwd;

	path = cmd_vector[1];	
	old_pwd = getcwd(0, 0);
	if (!chdir(path))
		error();
	new_pwd = getcwd(0, 0);
	envp_delete(envp_list, "PWD");
	envp_add(envp_list, "PWD", new_pwd);
	if (envp_find(envp_list, "OLDPWD"))
		envp_delete(envp_list, "OLDPWD");
	envp_add(envp_list, "OLDPWD", old_pwd);
}

void	bt_export(char **cmd_vector,t_list *envp_list)
{
	int		equal_i;
	int		word_i;
	char	*word;
	char	*key;
	char	*value;

	word_i = 1;
	while (cmd_vector[word_i])
	{
		word = cmd_vector[word_i];
		equal_i = bt_strchr(word, '=');
		if (equal_i <= 0)
			error_handle() ;
		key = bt_substr(word, 0, equal_i + 1);
		value = bt_substr(word, 0, bt_strlen(word) - equal_i);
		envp_add(envp_list, key, value);
		word_i++;
	}
}

/*
	error case
	export = / export a=b c=d / exprort a
*/

void	bt_unset(char **cmd_vector, t_list *envp_list)
{
	char	*key;
	
	key = cmd_vector[1];
	envp_delete(envp_list, key);
}