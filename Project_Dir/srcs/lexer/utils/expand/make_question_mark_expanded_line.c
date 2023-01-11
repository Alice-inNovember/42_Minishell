/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_question_mark_expanded_line.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:04:10 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/11 14:03:10 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/lexer.h"
#include "../../../../includes/envp.h"

extern t_exit_heredoc	g_exit_heredoc;

static char	*make_backline(char *line, int index)
{
	char	*backline;
	int		backline_start_index;
	int		backline_size;

	backline_start_index = index + 2;
	backline_size = ft_strlen(line) - backline_start_index;
	backline = ft_substr(line, backline_start_index, backline_size);
	return (backline);
}

char	*make_question_mark_expanded_line(t_asset *asset)
{
	char	*expanded_line;
	char	*frontline;
	char	*backline;
	char	*num_str;

	frontline = ft_substr(asset->line, 0, asset->index);
	backline = make_backline(asset->line, asset->index);
	num_str = ft_itoa(g_exit_heredoc.exit_status);
	expanded_line = ft_str4join(frontline, num_str, "\\", backline);
	free(frontline);
	free(backline);
	free(num_str);
	return (expanded_line);
}
