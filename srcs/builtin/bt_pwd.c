/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:35:50 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/13 10:01:33 by junlee2          ###   ########seoul.kr  */
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
