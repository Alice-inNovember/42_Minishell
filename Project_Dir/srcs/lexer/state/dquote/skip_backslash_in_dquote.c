/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_backslash_in_dquote.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:25:57 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/08 22:27:55 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/lexer.h"

void	skip_backslash_in_dquote(t_state *state, t_asset *asset)
{
	asset->index++;
	*state = BRANCH_DQUOTE;
}
