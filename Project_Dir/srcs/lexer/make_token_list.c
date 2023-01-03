/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_token_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:37:12 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/03 13:02:55 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer.h"

void	make_token_list(t_data *data)
{
	const t_state_fp	state_fp[TOTAL_STATE - 1] = {
		init, branch, making_word, making_pipe,
		making_less, making_dless, making_great, making_dgreat,
		quote_open, quote_close, dquote_open, dquote_close
	};
	t_state				state;
	t_list				buf_list;
	int					index;

	state = INIT;
	while (state != FINISH)
		state_fp[state](&state, data, &buf_list, &index);
}
