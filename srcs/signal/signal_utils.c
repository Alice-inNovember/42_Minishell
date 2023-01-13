/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:40:37 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/11 21:51:56 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/signal_handler.h"

static int	_wstatus(int status)
{
	int	return_val;

	return_val = status & 0177;
	return (return_val);
}

int	wifsignaled(int status)
{
	int	return_val;

	return_val = ((_wstatus(status) != 0177) && (_wstatus(status) != 0));
	return (return_val);
}

int	wtermsig(int status)
{
	int	return_val;

	return_val = _wstatus(status);
	return (return_val);
}

int	wexitstatus(int status)
{
	int	return_val;

	return_val = ((unsigned)status >> 8) & 0xff;
	return (return_val);
}
