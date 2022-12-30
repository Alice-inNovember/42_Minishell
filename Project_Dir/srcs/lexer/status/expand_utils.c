/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:20:08 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/30 11:38:47 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/lexer1.h"

int	is_heredoc_limit_string(t_list *token_lst)
{
	const t_token	*last_token = lst_peek_last_content(token_lst);

	if (last_token->type == T_DLESS)
		return (1);
	else
		return (0);
}

int	get_env_length(char *line)
{
	int	length;

	length = 0;
	while (line[length] == '_' || ft_isalpha(line[length]))
		length++;
	while (line[length] == '_' || ft_isalpha(line[length]) || \
			ft_isdigit(line[length]))
		length++;
	return (length);
}

int	is_proper_env(char *line)
{
	if (get_env_length(line) > 0)
		return (1);
	else
		return (0);
}
