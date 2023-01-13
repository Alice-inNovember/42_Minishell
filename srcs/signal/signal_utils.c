/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:40:37 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/13 12:29:08 by jincpark         ###   ########.fr       */
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
