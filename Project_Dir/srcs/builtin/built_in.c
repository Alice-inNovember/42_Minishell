/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:06:49 by tyi               #+#    #+#             */
/*   Updated: 2023/01/02 15:40:15 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "/Users/tyi/Documents/minishell/Project_Dir/libraries/libft/includes/libft.h"
# include "../../includes/minishell.h"
# include <sys/types.h>
# include <dirent.h>
# include "./../../libraries/dllist/includes/dllist.h"



int	check_word_cnt(char **cmd_vector)
{
	int	i;

	while (cmd_vector[i])
		i++;
	return (i);	
}

void	bt_echo(char **cmd_vector, t_list *envp_list) 
{
	char	*word;
	int		i;
	int		new_line_flag;

	new_line_flag = 1;
	i = 1;
	while (!ft_strcmp(cmd_vector[i], "-n"))
	{
		new_line_flag = 0;
		i++;
	}
	while (1) // while 조건 // $?
	{
		word = cmd_vector[i];
		printf("%s", cmd_vector[i]);
		if (!cmd_vector[i + 1])
			break ;
		printf(" ");
		i++;
	}
	if (new_line_flag == 1)
		printf("\n");
}


int	bt_cd(char **cmd_vector, t_list *envp_list)
{
	char	*path;
	char	*new_pwd;
	char	*old_pwd;

	if (check_word_cnt(cmd_vector) == 1)
		path = envp_find(envp_list, "HOME");
	else if (check_word_cnt(cmd_vector) == 2)
		path = cmd_vector[1];
	else
		error_handle();
	old_pwd = getcwd(0, 0);
	if (chdir(path))
	{
		error_handle();
		return (1);
	}
	new_pwd = getcwd(0, 0);
	envp_delete(envp_list, "PWD");
	envp_add(envp_list, "PWD", new_pwd);
	envp_delete(envp_list, "OLDPWD");
	envp_add(envp_list, "OLDPWD", old_pwd);
	return (0);
}





int	bt_pwd(char **cmd_vector, t_list *envp_list)
{
	char	*pwd;
	
	if (check_word_cnt(cmd_vector) != 1);
		return (1);
	pwd = envp_find(envp_list, "PWD");
	printf("%s\n", pwd);
	return (0);
}

// handel case
// all
// not handle case
// error case
// env word ...

int	bt_env(char **cmd_vector,t_list *envp_list)
{
	t_node	*cur_node;
	char	*key;
	char	*value;

	
	if (check_word_cnt(cmd_vector) != 1)
		return (1);
	cur_node = lst_peek_first(envp_list);
	while (cur_node != lst_peek_last(envp_list))
	{
		key = ((t_envp *)cur_node->content)->key;
		value = ((t_envp *)cur_node->content)->value;
		printf("%s=%s\n", key, value);
	}
	printf("_=/usr/bin/env\n");
	return (0);
}

void	bt_exit(char **cmd_vector,t_list *envp_list)
{
	if (check_word_cnt(cmd_vector) != 1);
		error_handle();
}


// handle case
// export a=b c=d
// 	error case
// export /	export =  / exprort a

int	ft_findchr_i(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	print_export(char **cmd_vector, t_list *envp_list)
{
	t_node	*cur_node;
	char	*key;
	char	*value;

	
	if (check_word_cnt(cmd_vector) != 1)
		error_handle();
	cur_node = lst_peek_first_node(envp_list);
	while (cur_node != lst_peek_last_node(envp_list))
	{
		key = ((t_envp *)cur_node->content)->key;
		value = ((t_envp *)cur_node->content)->value;
		printf("declare -x %s=\"%s\"\n", key, value);
		cur_node = cur_node->next;
	}
}

int	bt_export(char **cmd_vector,t_list *envp_list)
{
	int		equal_i;
	int		word_i;
	int		error_flag;
	char	*word;
	char	*key;
	char	*value;

	error_flag = 0;
	word_i = 1;
	while (cmd_vector[word_i]) // mid error continue
	{
		word = cmd_vector[word_i];
		equal_i = ft_findchr_i(word, '=');
		if (equal_i <= 0)
		{
			error_flag = 1; // if with pipe execution must exit(1);
			continue ;
		}
		key = ft_substr(word, 0, equal_i + 1);
		if (!is_proper_env(key)) // fdsfad
		{
			error_flag = 1;
			continue ;	
		}
		value = ft_substr(word, 0, ft_strlen(word) - equal_i);
		envp_delete(envp_list);
		envp_add(envp_list, key, value);
		word_i++;
	}
	if (word_i == 1)
		print_export(cmd_vector, envp_list);
	return (error_flag);
}

int bt_unset(char **cmd_vector, t_list *envp_list)
{
	int		error_flag;
	int		word_i;
	char	*key;

	
	error_flag = 0;
	word_i = 1;
	while (cmd_vector[word_i])
	{
		if (!is_proper_env(cmd_vector[word_i]))
		{
			error_flag = 1;
			continue ;
		}
		key = cmd_vector[word_i];
		envp_delete(envp_list, key);
	}
	return (error_flag);
}

int	main(int ac, char **av)
{
	char	**cmd_vec = av + 1;

	bt_echo(cmd_vec, 0);	
	return (0);
}
