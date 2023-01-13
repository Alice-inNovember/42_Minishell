/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:43:12 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/13 10:06:19 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/lexer.h"

void	close_quote(t_state *state, t_asset *asset)
{
	asset->index++;
	*state = MAKE_WORD_TOKEN;
}
