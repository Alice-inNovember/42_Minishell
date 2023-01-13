/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_expanded_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:38:48 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/lexer.h"
#include "../../../../includes/envp.h"

static char	*get_env_value(char *line, int index, t_list *envp_list)
{
	char	*env_value;
	char	*env_name;
	int		env_length;

	env_length = get_env_length(&line[index]);
	env_name = ft_substr(line, index, env_length);
	env_value = envp_find(envp_list, env_name);
	free(env_name);
	return (env_value);
}

static char	*cut_backline(char *line, int index)
{
	char	*backline;
	int		backline_start_index;
	int		backline_size;

	backline_start_index = index + get_env_length(&line[index + 1]) + 1;
	backline_size = ft_strlen(line) - backline_start_index;
	backline = ft_substr(line, backline_start_index, backline_size);
	return (backline);
}

char	*make_expanded_line(t_asset *asset)
{
	char	*expanded_line;
	char	*env_value;
	char	*frontline;
	char	*backline;

	env_value = get_env_value(asset->line, asset->index + 1, asset->envp_list);
	frontline = ft_substr(asset->line, 0, asset->index);
	backline = cut_backline(asset->line, asset->index);
	if (env_value == NULL)
		expanded_line = ft_str3join(frontline, "\\", backline);
	else
		expanded_line = ft_str4join(frontline, env_value, "\\", backline);
	free(frontline);
	free(backline);
	return (expanded_line);
}
