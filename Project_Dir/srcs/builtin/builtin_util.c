/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:54:10 by junlee2           #+#    #+#             */
/*   Updated: 2022/12/29 15:34:23 by junlee2          ###   ########seoul.kr  */
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

void	builtin_init(t_list *builtin_lst)
{
	void	*builtin;

	lst_init(builtin_lst);
	builtin = builtin_add("cd", bt_cd);
	lst_append(builtin_lst, new_node(builtin));
	builtin = builtin_add("echo", bt_echo);
	lst_append(builtin_lst, new_node(builtin));
	builtin = builtin_add("env", bt_env);
	lst_append(builtin_lst, new_node(builtin));
	builtin = builtin_add("exit", bt_exit);
	lst_append(builtin_lst, new_node(builtin));
	builtin = builtin_add("export", bt_export);
	lst_append(builtin_lst, new_node(builtin));
	builtin = builtin_add("pwd", bt_pwd);
	lst_append(builtin_lst, new_node(builtin));
	builtin = builtin_add("unset", bt_unset);
	lst_append(builtin_lst, new_node(builtin));
}

t_builtin_fp	builtin_find(t_list *builtin_lst, char *key)
{
	t_node	*node;

	node = lst_peek_first(builtin_lst);
	while (node->content && ft_strcmp(((t_builtin *)node->content)->key, key))
		node = node->next;
	if (node->content)
		return (((t_builtin *)node->content)->function);
	return (NULL);
}
