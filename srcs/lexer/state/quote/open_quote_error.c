/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_quote_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:38:55 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/13 10:06:21 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/lexer.h"

void	open_quote_error(t_state *state, t_asset *asset)
{
	*asset->syntax_err_flag = E_SINGLE_QUOTE;
	*state = CLEAR;
}
