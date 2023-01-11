/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_util3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:31:33 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/11 22:42:16 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	save_origin_io(int origin_io[2])
{
	origin_io[READ_END] = dup(STDIN_FILENO);
	origin_io[WRITE_END] = dup(STDOUT_FILENO);
}

void	restore_origin_io(int origin_io[2])
{
	dup2(origin_io[READ_END], STDIN_FILENO);
	close(origin_io[READ_END]);
	dup2(origin_io[WRITE_END], STDOUT_FILENO);
	close(origin_io[WRITE_END]);
}
