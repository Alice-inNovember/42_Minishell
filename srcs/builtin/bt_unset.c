/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:33:33 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/envp.h"
#include "../../includes/builtin.h"

int	is_proper_env(char *env_name);

int	bt_unset(char **cmd_vector, t_list *envp_list)
{
	int		error_flag;
	int		word_i;
	char	*key;

	error_flag = EX_SUCCESS;
	word_i = 1;
	while (cmd_vector[word_i])
	{
		if (!is_proper_env(cmd_vector[word_i]))
		{
			error_flag = EX_BT_FAIL;
			error_handler_for_bt("unset", cmd_vector[word_i], INVALID_ARG);
			word_i++;
			continue ;
		}
		else
		{
			key = cmd_vector[word_i];
			envp_delete(envp_list, key);
			word_i++;
		}
	}
	return (error_flag);
}
