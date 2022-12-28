/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:19:19 by junlee2           #+#    #+#             */
/*   Updated: 2022/12/28 09:47:55 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "../../includes/data.h"
#include "../../includes/minishell.h"
#include "../../libraries/dllist/includes/dllist.h"
#include "../../libraries/libft/includes/libft.h"

size_t	find_keyend(char *key)
{
	int	i;

	i = 0;
	while (key[i] && key[i] != '=')
		i++;
	return (i);
}

void	envp_add(t_data *data, char *key, char *value)
{
	t_envp	*e_node;

	e_node = ft_calloc(1, sizeof(t_envp *));
	e_node->key = ft_strdup(key);
	e_node->value = ft_strdup(value);
	lst_append(&data->envp_lst, new_node(e_node));
}

void	envp_init(t_data *data, char **envp)
{
	int		i;
	size_t	keyend;
	char	*key;

	lst_init(&data->envp_lst);
	i = 0;
	while (envp[i])
	{
		keyend = find_keyend(envp[i]);
		key = ft_substr(envp[i], 0, keyend);
		envp_add(data, key, ft_strdup(ft_strchr(envp[i], '=') + 1));
		free(key);
		i++;
	}
}

char	*envp_find(t_data *data, const char *key)
{
	t_node	*node;

	node = data->envp_lst.head->next;
	while (ft_strcmp(((t_envp *)node->content)->key, key))
		node = node->next;
	return (((t_envp *)node->content)->value);
}
