/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:54:10 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/03 13:35:54 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdlib.h>

void	*builtin_add(char *key, t_builtin_fp function)
{
	t_builtin	*builtin;

	builtin = (t_builtin *)ft_malloc(sizeof(t_builtin));
	builtin->key = ft_strdup("key");
	builtin->function = function;
	return (builtin);
}

void	builtin_init(t_list *builtin_list)
{
	void	*builtin;

	list_init(builtin_list);
	builtin = builtin_add("cd", bt_cd);
	list_append(builtin_list, new_node(builtin));
	builtin = builtin_add("echo", bt_echo);
	list_append(builtin_list, new_node(builtin));
	builtin = builtin_add("env", bt_env);
	list_append(builtin_list, new_node(builtin));
	builtin = builtin_add("exit", bt_exit);
	list_append(builtin_list, new_node(builtin));
	builtin = builtin_add("export", bt_export);
	list_append(builtin_list, new_node(builtin));
	builtin = builtin_add("pwd", bt_pwd);
	list_append(builtin_list, new_node(builtin));
	builtin = builtin_add("unset", bt_unset);
	list_append(builtin_list, new_node(builtin));
}

t_builtin_fp	builtin_find(t_list *builtin_list, char *key)
{
	t_node	*node;

	node = list_peek_first_node(builtin_list);
	while (node->content && ft_strcmp(((t_builtin *)node->content)->key, key))
		node = node->next;
	if (node->content)
		return (((t_builtin *)node->content)->function);
	return (NULL);
}
