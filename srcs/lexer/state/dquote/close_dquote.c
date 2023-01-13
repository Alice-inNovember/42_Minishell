/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_dquote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:13:24 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/12 19:11:46 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/lexer.h"

void	close_dquote(t_state *state, t_asset *asset)
{
	asset->index++;
	*state = MAKE_WORD_TOKEN;
}
