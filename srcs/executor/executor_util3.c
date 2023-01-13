/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_util3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:31:33 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/13 10:00:23 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../includes/data.h"

void	save_origin_io(int origin_io[2])
{
	origin_io[READ_END] = ft_dup(STDIN_FILENO);
	origin_io[WRITE_END] = ft_dup(STDOUT_FILENO);
}

void	restore_origin_io(int origin_io[2])
{
	ft_dup2(origin_io[READ_END], STDIN_FILENO);
	close(origin_io[READ_END]);
	ft_dup2(origin_io[WRITE_END], STDOUT_FILENO);
	close(origin_io[WRITE_END]);
}
