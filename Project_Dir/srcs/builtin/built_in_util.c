/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:54:10 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/04 14:46:11 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdio.h>
#include <stdlib.h>

void	builtin_add(t_list *builtin_list, char *key, t_builtin_fp function)
{
	t_builtin	*bt_node;

	bt_node = (t_builtin *)ft_calloc(1, sizeof(t_envp));
	bt_node->key = ft_strdup(key);
	bt_node->function = function;
	list_append(builtin_list, new_node(bt_node));
}

void	builtin_init(t_list *builtin_list)
{
	void	*builtin;

	list_init(builtin_list);
	builtin_add(builtin_list, "cd", bt_cd);
	builtin_add(builtin_list, "echo", bt_echo);
	builtin_add(builtin_list, "env", bt_env);
	builtin_add(builtin_list, "exit", bt_exit);
	builtin_add(builtin_list, "export", bt_export);
	builtin_add(builtin_list, "pwd", bt_pwd);
	builtin_add(builtin_list, "unset", bt_unset);
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
