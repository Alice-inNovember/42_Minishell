/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_export_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:33:49 by tyi               #+#    #+#             */
/*   Updated: 2023/01/06 16:14:01 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"

void	print_export(t_list *envp_list);

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

// // commit할 떄 out

// int	get_env_length(char *line)
// {
// 	int	length;

// 	length = 0;
// 	while (line[length] == '_' || ft_isalpha(line[length]))
// 		length++;
// 	if (length == 0)
// 		return (0);
// 	while (line[length] == '_' || 
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

int	check_word_sep_key_val(char *word, \
char **key, char **value, int *error_flag)
{
	int		equal_i;

	equal_i = ft_findchr_i(word, '=');
	if (equal_i == 0)
	{
		*error_flag = EX_BT_FAIL;
		error_handler("export", word, INVALID_ARG);
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
		error_handler("export", word, INVALID_ARG);
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
