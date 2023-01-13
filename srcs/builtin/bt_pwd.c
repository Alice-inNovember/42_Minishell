/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:35:50 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../includes/builtin.h"

int	bt_pwd(char **cmd_vector, t_list *envp_list)
{
	char	*pwd;

	((void) cmd_vector, (void) envp_list);
	pwd = getcwd(0, 0);
	printf("%s\n", pwd);
	free (pwd);
	return (EX_SUCCESS);
}
