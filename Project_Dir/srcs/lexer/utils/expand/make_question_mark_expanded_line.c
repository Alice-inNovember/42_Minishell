/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_question_mark_expanded_line.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:04:10 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/08 22:11:22 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/lexer.h"
#include "../../../../includes/envp.h"

extern int	g_last_exit_status;

char	*make_question_mark_expanded_line(t_asset *asset)
{
	char	*expanded_line;
	char	*frontline;
	char	*backline;
	int		backline_start_index;
	int		backline_size;

	frontline = ft_substr(asset->line, 0, asset->index);
	backline_start_index = asset->index + 2;
	backline_size = ft_strlen(asset->line) - backline_start_index;
	backline = ft_substr(asset->line, backline_start_index, backline_size);
	expanded_line = ft_str4join(frontline, \
								ft_itoa(g_last_exit_status), "\\", backline);
	free(frontline);
	free(backline);
	return (expanded_line);
}
