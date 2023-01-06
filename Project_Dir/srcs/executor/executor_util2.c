/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_util2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:43:41 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/06 09:55:08 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <sys/_types/_pid_t.h>

void	pid_list_add(t_list *pidlist, pid_t pid)
{
	pid_t	*pidptr;

	pidptr = ft_malloc(sizeof(pid_t));
	*pidptr = pid;
	list_append(pidlist, new_node(pidptr));
}
