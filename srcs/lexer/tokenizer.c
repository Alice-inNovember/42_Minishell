/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:50:44 by tyi          #+#    #+#             */
/*   Updated: 2023/01/12 19:24:09 by tyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer.h"

void	init_asset(t_asset *asset, t_data *data)
{
	asset->line = ft_strdup(data->line);
	asset->index = 0;
	asset->envp_list = &data->envp_list;
	asset->token_list = &data->token_list;
	list_init(&asset->buf_list);
	asset->syntax_err_flag = &data->syntax_err_flag;
}

void	tokenizer(t_data *data)
{
	const t_state_fp	state_fp[TOTAL_STATE - 1] = {
		start, branch, skip_space, add_buf_pipe, make_pipe_token,
		add_buf_less, branch_less, make_less_token,
		add_buf_dless, make_dless_token,
		add_buf_great, branch_great, make_great_token,
		add_buf_dgreat, make_dgreat_token,
		add_buf_word, make_word_token,
		check_expand, expand, question_mark_expand, branch_expand,
		skip_space_in_expand, add_buf_in_expand, make_word_token_expand,
		expand_end,
		open_quote, branch_quote, open_quote_error, add_buf_in_quote,
		close_quote,
		open_dquote, branch_dquote, skip_backslash_in_dquote, open_dquote_error,
		add_buf_in_dquote, check_expand_dquote, expand_dquote,
		question_mark_expand_dquote, close_dquote,
		clear
	};
	t_asset				asset;
	t_state				state;

	init_asset(&asset, data);
	state = START;
	while (state != FINISH)
		state_fp[state](&state, &asset);
}
