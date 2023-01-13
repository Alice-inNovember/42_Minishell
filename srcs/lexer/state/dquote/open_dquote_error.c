/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_dquote_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:41:08 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/08 19:41:16 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/lexer.h"

void	open_dquote_error(t_state *state, t_asset *asset)
{
	*asset->syntax_err_flag = E_SINGLE_DQUOTE;
	*state = CLEAR;
}
