/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:06:49 by tyi               #+#    #+#             */
/*   Updated: 2022/12/29 13:51:47 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../Project_Dir/includes/data.h>
#include </Users/tyi/Documents/minishell_git/Project_Dir/includes/envp.h>

void	ft_echo(char **cmd_vector, t_list envp_list)
{
	int	i;
	int	new_line_flag;

	if (ft_strcmp(cmd_vector[1], "-n"))
	{
		new_line_flag = 0;
		i = 2;
	}
	else
	{
		new_line_flag = 1;
		i = 1;
	}
	while (cmd_vector[i])
	{
		ft_printf("%s", cmd_vector[i]);
		i++;
	}
	if (new_line_flag == 1)
		ft_printf("\n");
}

void	ft_cd(char **cmd_vector, t_list *envp_list)
{
	t_envp	*node_p;

	node_p = find_node_type_p(envp_list, "PWD");
	node_p->content-> =
}

void	ft_pwd(char **cmd_vector, t_list envp_list)
{
	char	*pwd;
	pwd = envp_find(envp_find, "PWD");
	ft_printf("%s\n", pwd);
}

void	ft_export(char **cmd_vector, t_list envp_list)
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
		equal_i = ft_strchr(word, '=');
		if (equal_i <= 0)
			error_handle() ;
		key = ft_substr(word, 0, equal_i + 1);
		value = ft_substr(word, 0, ft_strlen(word) - equal_i);
		envp_add(envp_list, key, value);
		word_i++;
	}
}

/*
	error case
	export = / export a=b c=d / exprort a
*/

void	ft_unset(char **cmd_vector, t_list envp_list)
{

}

void	ft_env(char **cmd_vector, t_list envp_list)
{

}

void	ft_exit(char **cmd_vector, t_list envp_list)
{

}
