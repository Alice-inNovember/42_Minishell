/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_token_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:37:25 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/02 19:05:22 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/lexer1.h"

void	init_pack(t_pack *pack, t_list *token_lst, t_list *envp_lst, char *line)
{
	lst_init(token_lst);
	pack->token_lst = token_lst;
	pack->envp_lst = envp_lst;
	lst_init(&pack->buffer_lst);
	pack->line = line;
	pack->index = 0;
}

void	error_handle(t_status *status, t_pack *pack)
{
	if (*status == QUOTE_ERROR)
		printf("Syntax error: open quote\n");
	else if (*status == DQUOTE_ERROR)
		printf("Syntax error: open dquote\n");
	free_pack(pack);
}

int	make_token_list(t_data *data, char *line)
{
	const t_status_fp	status_fp[TOTAL_STATUS - 3] = {
		branch, making_word, making_pipe, \
		making_less, making_dless, making_great, making_dgreat, \
		quote_open, quote_close, dquote_open, dquote_close, \
		expand, dquote_expand
	};
	t_status			status;
	t_pack				pack;

	init_pack(&pack, &data->token_lst, &data->envp_lst, line);
	status = BRANCH;
	while (status != FINISH && status != QUOTE_ERROR && status != DQUOTE_ERROR)
		status_fp[status](&status, &pack);
	if (status != FINISH)
	{
		error_handle(&status, &pack);
		return (1);
	}
	return (0);
}
