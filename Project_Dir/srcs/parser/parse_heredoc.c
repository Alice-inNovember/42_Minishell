/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:19:30 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/06 09:20:00 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data.h"
#include "../../includes/parser.h"

void	parse_io_here(t_data *data, t_proc_data *proc_data, t_list *token_list)
{
	t_redir	*redir;

	if (is_return_case(data, token_list, E_NONE))
		return ;
	redir = (t_redir *)ft_calloc(1, sizeof(t_redir));
	redir->type = T_DLESS;
	redir->fname = make_temp_file(data);
	list_append(&proc_data->redir_list, new_node(redir));
}
