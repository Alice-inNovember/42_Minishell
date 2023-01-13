/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:54:10 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/13 12:37:53 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../libraries/dllist/includes/dllist.h"
#include "../../includes/builtin.h"

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

int	check_word_cnt(char **cmd_vector)
{
	int	i;

	i = 0;
	while (cmd_vector[i])
		i++;
	return (i);
}

void	error_handler_for_bt(char *cmd, char *word, int status)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	if (word)
		ft_putstr_fd(": ", 2);
	ft_putstr_fd(word, 2);
	if (status == HOME_NOT)
		ft_putstr_fd(": HOME not set\n", 2);
	else if (status == CANT_CD)
		ft_putstr_fd(": can't change directory\n", 2);
	else if (status == MANY_ARG)
		ft_putstr_fd(": too many arguments\n", 2);
	else if (status == NOT_NUM_ARG)
		ft_putstr_fd(": numeric argumnet required\n", 2);
	else if (status == INVALID_ARG)
		ft_putstr_fd(": not a valid identifier\n", 2);
}

//  all error message is not direct to STDOUT, only to STDERR
