/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:35:35 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../includes/builtin.h"

int	bt_env(char **cmd_vector, t_list *envp_list)
{
	t_node	*cur_node;
	char	*key;
	char	*value;

	if (check_word_cnt(cmd_vector) != 1)
	{
		error_handler_for_bt("env", 0, MANY_ARG);
		return (EX_CNOT_EXEC);
	}
	cur_node = list_peek_first_node(envp_list);
	while (cur_node->next)
	{
		key = ((t_envp *)cur_node->content)->key;
		value = ((t_envp *)cur_node->content)->value;
		if (value)
			printf("%s=%s\n", key, value);
		cur_node = cur_node->next;
	}	
	return (EX_SUCCESS);
}

//line 32 : when "export a", export : key = a value = NULL, not print
