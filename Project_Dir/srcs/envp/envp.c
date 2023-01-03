/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:19:19 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/03 13:35:59 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data.h"
#include "../../includes/minishell.h"

char	*envp_find(t_list *envp_list, char *key)
{
	t_node	*node;

	node = list_peek_first_node(envp_list);
	while (node->content && ft_strcmp(((t_envp *)node->content)->key, key))
		node = node->next;
	if (node->content)
		return (((t_envp *)node->content)->value);
	return (NULL);
}

void	envp_edit(t_list *envp_list, char *key, char *value)
{
	t_node	*node;

	node = list_peek_first_node(envp_list);
	while (node->content && ft_strcmp(((t_envp *)node->content)->key, key))
		node = node->next;
	free(((t_envp *)node->content)->value);
	((t_envp *)node->content)->value = ft_strdup(value);
}

void	envp_add(t_list *envp_list, char *key, char *value)
{
	t_envp	*e_node;

	if (envp_find(envp_list, key))
		return (envp_edit(envp_list, key, value));
	e_node = (t_envp *)ft_calloc(1, sizeof(t_envp));
	e_node->key = ft_strdup(key);
	e_node->value = ft_strdup(value);
	list_append(envp_list, new_node(e_node));
}

void	envp_init(t_list *envp_list, char **envp)
{
	int		i;
	size_t	keyend;
	char	*key;
	char	*value;

	list_init(envp_list);
	i = 0;
	while (envp[i])
	{
		keyend = 0;
		while (envp[i][keyend] && envp[i][keyend] != '=')
			keyend++;
		key = ft_substr(envp[i], 0, keyend);
		value = ft_strdup(ft_strchr(envp[i], '=') + 1);
		envp_add(envp_list, key, value);
		ft_free((void **)&key);
		ft_free((void **)&value);
		i++;
	}
}

void	envp_delete(t_list *envp_list, char *key)
{
	t_node	*node;

	node = list_peek_first_node(envp_list);
	while (ft_strcmp(((t_envp *)node->content)->key, key))
		node = node->next;
	if (!node->content)
		return ;
	ft_free((void **)&((t_envp *)node->content)->value);
	ft_free(node->content);
	node->prev->next = node->next;
	node->next->prev = node->prev;
	ft_free((void **)&node);
}
