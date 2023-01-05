/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_token_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:37:12 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/05 20:24:58 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	make_token_list(t_data *data)
{
	const t_state_fp	state_fp[TOTAL_STATE - 1] = {
		init, branch, skip_space, making_word, making_pipe,
		making_less, making_dless, making_great, making_dgreat,
		quote_branch, quote_making_word, quote_close,
		dquote_branch, dquote_making_word, dquote_close,
		expand, dquote_expand, clear
	};
	t_state				state;
	t_list				buf_list;
	int					idx;

	state = INIT;
	while (state != FINISH)
		state_fp[state](&state, data, &buf_list, &idx);
}
