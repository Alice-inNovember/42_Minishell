/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_quote_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:38:55 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/lexer.h"

void	open_quote_error(t_state *state, t_asset *asset)
{
	*asset->syntax_err_flag = E_SINGLE_QUOTE;
	*state = CLEAR;
}
