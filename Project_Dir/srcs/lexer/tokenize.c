/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:37:25 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/30 14:07:06 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/lexer1.h"

void	tokenize(t_data *data, char *line)
{
	const t_status_fp	status_fp[TOTAL_STATUS - 1] = {
		branch, making_word, making_pipe, \
		making_less, making_dless, making_great, making_dgreat, \
		quote_open, quote_close, dquote_open, dquote_close, \
		expand, dquote_expand, quote_error, dquote_error
	};
	t_status			status;
	t_list				buffer_lst;

	lst_init(&data->token_lst);
	lst_init(&buffer_lst);
	status = BRANCH;
	while (status != FINISH)
		status_fp[status](&status, data, &line, &buffer_lst);
	lst_clear(&buffer_lst, NULL);
}
