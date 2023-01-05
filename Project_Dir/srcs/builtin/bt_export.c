/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:33:49 by tyi               #+#    #+#             */
/*   Updated: 2023/01/05 23:12:07 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"

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
	key_arr = ft_calloc(list_size(envp_list) + 1, sizeof(char *));
	cur_node = list_peek_first_node(envp_list);
	while (cur_node->next)
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
		j = i + 1;
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
	free(key_arr);
}

// commit할 떄 out

// int	get_env_length(char *line)
// {
// 	int	length;

// 	length = 0;
// 	while (line[length] == '_' || ft_isalpha(line[length]))
// 		length++;
// 	if (length == 0)
// 		return (0);
// 	while (line[length] == '_' || \
// 			ft_isalpha(line[length]) || ft_isdigit(line[length]))
// 		length++;
// 	return (length);
// }

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
	if (equal_i == 0)
	{
		*error_flag = EX_BT_FAIL;
		perror("bash: export: not a valid identifier");
		return (1);
	}
	else if (equal_i == -1)
	{
		*error_flag = EX_BT_FAIL;
		return (1);
	}
	*key = ft_substr(word, 0, equal_i);
	if (!is_proper_env(*key))
	{
		*error_flag = EX_BT_FAIL;
		perror("bash: export: not a valid identifier");
		free(*key);
		return (1);
	}
	*value = ft_substr(word, equal_i + 1, ft_strlen(word) - equal_i - 1);
	return (0);
}

int	bt_export(char **cmd_vector, t_list *envp_list)
{
	int		word_i;
	int		error_flag;
	char	*word;
	char	*key;
	char	*value;

	error_flag = EX_SUCCESS;
	word_i = 1;
	if (check_word_cnt(cmd_vector) == 1)
		print_export(envp_list);
	while (cmd_vector[word_i])
	{
		word = cmd_vector[word_i];
		word_i++;
		if (check_word_sep_key_val(word, &key, &value, &error_flag))
			continue ;
		printf("key : \"%s\" \n value \"%s\" \n", key, value);
		envp_add(envp_list, key, value);
		(free(key), free(value));
	}
	return (error_flag);
}
