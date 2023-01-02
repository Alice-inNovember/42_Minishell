/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 09:06:43 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/30 15:39:21 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/lexer1.h"

void	expand(t_status *status, t_data *data, char **line, t_list *buffer_lst)
{
	char	*expanded_line;

	if (!is_proper_env(*line + 1) || is_heredoc_limit_string(&data->token_lst))
	{
		*status = MAKING_WORD;
		return ;
	}
	(*line)++;
	expanded_line = make_expanded_line(*line, &data->envp_lst);
	*line = expanded_line;
	ft_free((void **)&data->line);
	data->line = expanded_line;
	*status = MAKING_WORD;
}
