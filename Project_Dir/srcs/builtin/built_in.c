/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:06:49 by tyi               #+#    #+#             */
/*   Updated: 2023/01/02 16:44:55g by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../libraries/libft/includes/libft.h"
# include "../../includes/minishell.h"
# include <sys/types.h>
# include <dirent.h>
# include "./../../libraries/dllist/includes/dllist.h"
# include <stdio.h>  
# include <readline/readline.h>
# include <readline/history.h>

int	check_word_cnt(char **cmd_vector)
{
	int	i;

	i = 0;
	while (cmd_vector[i])
		i++;
	return (i);	
}

void	print_word(char *word)
{
	int	i;

	i = 0;
	while (word[i])
	{	
		if (!ft_strncmp(word + i, "$?", 2))
		{
			printf("%d", g_last_exit_status);
			i = i + 2;
		}
		else
		{
			ft_putchar_fd(word[i], 1);
			i++;
		}
	}
}

int	bt_echo(char **cmd_vector, t_list *envp_list) 
{
	int		i;
	int		new_line_flag;

	(void)envp_list;
	new_line_flag = 1;
	i = 1;
	while (!ft_strcmp(cmd_vector[i], "-n"))
	{
		new_line_flag = 0;
		i++;
	}
	while (1) // while 조건 // $?
	{
		print_word(cmd_vector[i]);
		if (!cmd_vector[i + 1])
			break ;
		ft_putchar_fd(' ', 1);
		i++;
	}
	if (new_line_flag == 1)
		printf("\n");
	return (0);
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
		return (1);
	old_pwd = getcwd(0, 0);
	if (chdir(path))
		return (1);
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
	
	if (check_word_cnt(cmd_vector) != 1)
	{
		perror("error");
		return (1);
	}
	pwd = envp_find(envp_list, "PWD");
	printf("%s\n", pwd);
	return (0);
}

int	bt_env(char **cmd_vector,t_list *envp_list)
{
	t_node	*cur_node;
	char	*key;
	char	*value;

	if (check_word_cnt(cmd_vector) != 1)
		return (1);
	cur_node = list_peek_first_node(envp_list);
	while (cur_node != list_peek_last_node(envp_list))
	{
		key = ((t_envp *)cur_node->content)->key;
		value = ((t_envp *)cur_node->content)->value;
		printf("%s=%s\n", key, value);
		cur_node = cur_node->next;
	}
	return (0);
}

void	ft_error_manage(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

int	ft_atoi_in_bt(const char *str)
{
	unsigned long	res;
	int				sign;
	int				i;

	sign = 1;
	res = 0;
	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i ++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		ft_error_manage();
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = 10 * (res) + str[i++] - '0';
		if ((res > 2147483647 && sign == 1) || (res > 2147483648 && sign == -1))
			ft_error_manage();
	}
	if (str[i])
		ft_error_manage();
	return (sign * res);
}


int	bt_exit(char **cmd_vector, t_list *envp_list)
{
	
	int	status;	

	(void)envp_list;
	if (check_word_cnt(cmd_vector) == 1)
		status = 0;
	else if (check_word_cnt(cmd_vector) == 2)
		status = ft_atoi_in_bt(cmd_vector[1]);
	else
		return (1);	
	if (status == -1)
		return (1);
	exit((unsigned char)status);
	return ((unsigned char)status);
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



char	**make_key_arr(t_list *envp_list)
{
	int		i;
	t_node	*cur_node;
	char	**key_arr;

	i = 0;
	key_arr = malloc(sizeof(char *) * list_size(envp_list) + 1);
	cur_node = list_peek_first_node(envp_list);
	while (cur_node != list_peek_last_node(envp_list))
	{
		key_arr[i] = ((t_envp *)cur_node->content)->key;
		cur_node = cur_node->next;
		i++;
	}
	key_arr[i] = 0;
	return (key_arr);
}

void	make_order_key_arr(char **key_arr)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (key_arr[i])
	{
		j = i+ 1;
		while (key_arr[j])
		{	
			if (ft_strcmp(key_arr[i], key_arr[j]) > 0)
			{
				temp = key_arr[i];
				key_arr[i] = key_arr[j];
				key_arr[j] = temp;
			}
			j++;
		}
		i++;
	}
} 

void	print_export(t_list *envp_list)
{
	char	**key_arr;
	int		i;
	char	*key;
	char	*value;

	i = 0;
	key_arr = make_key_arr(envp_list);
	make_order_key_arr(key_arr);
	while (key_arr[i])
	{
		key = key_arr[i];
		value = envp_find(envp_list, key);
		printf("declare -x %s=\"%s\"\n", key, value);
		i++;
	}	
	free (key_arr);
}

int	is_proper_env(char *env_name)
{
	int	full_length;
	int	env_length;

	full_length = ft_strlen(env_name);
	env_length = get_env_length(env_name);
	if (full_length == env_length)
		return (1);
	else
		return (0);
}

int	check_word_sep_key_val(char *word, char **key, char **value, int *error_flag)
{
	int		equal_i;

	equal_i = ft_findchr_i(word, '=');
	if (equal_i <= 0)
	{
		*error_flag = 1; // if with pipe execution must exit(1);
		return (1);
	}
	*key = ft_substr(word, 0, equal_i);
	if (!is_proper_env(*key)) // fdsfad
	{
		*error_flag = 1;
		free(*key);
		return (1);
	}
	*value = ft_substr(word, equal_i + 1, ft_strlen(word) - equal_i - 1);
	return (0);
}

int	bt_export(char **cmd_vector,t_list *envp_list)
{
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
		if (check_word_sep_key_val(word, &key, &value, &error_flag))
			continue ;
		(envp_delete(envp_list, key), envp_add(envp_list, key, value));
		(free(key), free(value));
		word_i++;
	}
	if (word_i == 1)
		print_export(envp_list);
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
		word_i++;
	}
	return (error_flag);
}

// int	main(int ac, char **av, char **envp)
// {
// 	char	*line;
// 	char	**vec;
// 	t_list	envp_list;
	
// 	(void) ac;
// 	(void) av;
// 	envp_init(&envp_list, envp);
// 	while (1)
// 	{
// 		line = readline("minishell > ");
// 		add_history(line);
// 		vec = ft_split(line, ' ');
// 		if (!ft_strcmp(vec[0], "echo"))
// 			bt_echo(vec, &envp_list);
// 		else if (!ft_strcmp(vec[0], "pwd"))
// 			bt_pwd(vec, &envp_list);
// 		else if (!ft_strcmp(vec[0], "unset"))
// 			bt_unset(vec, &envp_list);
// 		else if (!ft_strcmp(vec[0], "cd"))
// 			bt_cd(vec, &envp_list);
// 		else if (!ft_strcmp(vec[0], "env"))
// 			bt_env(vec, &envp_list);
// 		else if (!ft_strcmp(vec[0], "export"))
// 			bt_export(vec, &envp_list);
// 		else if (!ft_strcmp(vec[0], "exit"))
// 			bt_exit(vec, &envp_list);
// 		else 		
// 			printf("no_command\n");
// 	}
// 	return (0);
// }
