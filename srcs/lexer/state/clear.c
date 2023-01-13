/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:01:47 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/08 18:03:46 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/lexer.h"

void	clear(t_state *state, t_asset *asset)
{
	free(asset->line);
	list_clear(&asset->buf_list, free);
	*state = FINISH;
}
