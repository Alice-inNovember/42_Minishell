/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_quote_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:38:55 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/08 19:41:00 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/lexer.h"

void	open_quote_error(t_state *state, t_asset *asset)
{
	*asset->syntax_err_flag = E_SINGLE_QUOTE;
	*state = CLEAR;
}
