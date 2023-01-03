/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:39:27 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/03 16:08:44 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/lexer.h"

int	get_env_length(char *line)
{
	int	length;

	length = 0;
	while (line[length] == '_' || ft_isalpha(line[length]))
		length++;
	if (length == 0)
		return (0);
	while (line[length] == '_' || \
			ft_isalpha(line[length]) || ft_isdigit(line[length]))
		length++;
	return (length);
}

int	is_heredoc_limiter(t_list *token_list)
{
	t_token	*last_token;

	last_token = list_peek_last_content(token_list);
	if (last_token != NULL && last_token->type == T_DLESS)
		return (1);
	else
		return (0);
}

int	is_expansion(char *line, int idx, t_list *token_list)
{
	if (get_env_length(&line[idx + 1]) > 0 && !is_heredoc_limiter(token_list))
		return (1);
	else
		return (0);
}
