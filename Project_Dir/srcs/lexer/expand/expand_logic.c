/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:20:34 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/06 16:40:05 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/lexer.h"
#include "../../../includes/envp.h"
#include <stdio.h>

extern int	g_last_exit_status;

char	*join_three_strings(char *front, char *env_value, char *back)
{
	char	*expanded_line;
	char	*temp;

	temp = ft_strjoin(front, env_value);
	expanded_line = ft_strjoin(temp, back);
	free(temp);
	return (expanded_line);
}

char	*expand_question_mark(char *line, int idx)
{
	char	*expanded_line;
	char	*front;
	char	*back;
	int		start_index;
	int		back_size;

	front = ft_substr(line, 0, idx);
	start_index = idx + 2;
	back_size = ft_strlen(line) - start_index;
	back = ft_substr(line, start_index, back_size);
	expanded_line = join_three_strings(front, \
			ft_itoa(g_last_exit_status), back);
	return (expanded_line);
}

char	*get_env_value(t_data *data, int idx)
{
	int		env_length;
	char	*env_name;
	char	*env_value;

	env_length = get_env_length(&data->line[idx]);
	env_name = ft_substr(data->line, idx, env_length);
	env_value = envp_find(&data->envp_list, env_name);
	free(env_name);
	return (env_value);
}

char	*cut_back(char *line, int idx)
{
	char	*back;
	int		start_index;
	int		back_size;

	start_index = idx + get_env_length(&line[idx + 1]) + 1;
	back_size = ft_strlen(line) - start_index;
	back = ft_substr(line, start_index, back_size);
	return (back);
}

char	*make_expanded_line(t_data *data, int idx)
{
	char	*expanded_line;
	char	*env_value;
	char	*front;
	char	*back;

	if (data->line[idx + 1] == '?')
	{
		expanded_line = expand_question_mark(data->line, idx);
		return (expanded_line);
	}
	env_value = get_env_value(data, idx + 1);
	front = ft_substr(data->line, 0, idx);
	back = cut_back(data->line, idx);
	if (env_value == NULL)
		expanded_line = ft_strjoin(front, back);
	else
		expanded_line = join_three_strings(front, env_value, back);
	free(front);
	free(back);
	return (expanded_line);
}
