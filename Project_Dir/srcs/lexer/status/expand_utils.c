/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:20:08 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/02 16:56:08 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/lexer1.h"

char	*get_env_value(char *line, int index, t_list *envp_lst)
{
	char	*env_name;
	char	*env_value;
	int		env_length;

	env_length = get_env_length(&line[index + 1]);
	env_name = ft_substr(line, index + 1, env_length);
	env_value = envp_find(envp_lst, env_name);
	ft_free((void **)&env_name);
	return (env_value);
}

char	*cut_back(char *line, int index)
{
	char	*back;
	int		env_length;
	int		line_length;
	int		back_length;

	env_length = get_env_length(&line[index + 1]);
	line_length = ft_strlen(line);
	back_length = line_length - (index + env_length + 1);
	back = ft_substr(line, index + env_length, back_length);
	return (back);
}

char	*make_expanded_line(char *line, int index, t_list *envp_lst)
{
	char		*expanded_line;
	char		*env_value;
	const char	*front = ft_substr(line, 0, index);
	const char	*back = cut_back(line, index);
	char		*temp_line;

	env_value = get_env_value(line, index, envp_lst);
	if (env_value == NULL)
		expanded_line = ft_strjoin(front, back);
	else
	{
		temp_line = ft_strjoin(front, env_value);
		expanded_line = ft_strjoin(temp_line, back);
		ft_free((void **)&temp_line);
	}
	ft_free((void **)&front);
	ft_free((void **)&back);
	ft_free((void **)&line);
	return (expanded_line);
}

int	is_heredoc_limit_string(t_list *token_lst)
{
	const t_token	*last_token = lst_peek_last_content(token_lst);

	if (last_token != NULL && last_token->type == T_DLESS)
		return (1);
	else
		return (0);
}

int	get_env_length(char *line)
{
	int	length;

	length = 0;
	while (line[length] == '_' || ft_isalpha(line[length]))
		length++;
	if (length == 0)
		return (length);
	while (line[length] == '_' || ft_isalpha(line[length]) || \
			ft_isdigit(line[length]))
		length++;
	return (length);
}

int	is_proper_env(char *line)
{
	if (get_env_length(line) > 0)
		return (1);
	else
		return (0);
}
