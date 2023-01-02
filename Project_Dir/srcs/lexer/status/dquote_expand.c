/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dquote_expand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 09:07:12 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/02 21:16:35 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/lexer1.h"

void	dquote_expand(t_status *status, t_pack *pack)
{
	char	*expanded_line;

	expanded_line = make_expanded_line(pack->line, pack->index, pack->envp_lst);
	pack->line = expanded_line;
	*status = DQUOTE_OPEN;
	pack->index--;
}
