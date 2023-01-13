/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:18:32 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/12 15:00:25 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data.h"
#include "../../libraries/libft/includes/libft.h"

void	error_msg(char *target, int errnum)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(target, 2);
	if (errnum == EN_CNOT_FIND)
		ft_putstr_fd(": command not found", 2);
	else if (errnum == EN_IS_DIR)
		ft_putstr_fd(": is a directory", 2);
	else if (errnum == EN_PER_DENIED)
		ft_putstr_fd(": Permission denied", 2);
	else if (errnum == EN_FNOT_FIND)
		ft_putstr_fd(": no such file or directory", 2);
	ft_putstr_fd("\n", 2);
}
