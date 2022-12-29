/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:43:28 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/29 22:18:29 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/lexer1.h"

void	del_token(void *content)
{
	t_token	*token;

	token = content;
	ft_free((void **)&token->value);
}

void	copy_buffer(char *value, t_list *buffer_lst)
{
	t_node	*cur_node;
	int		i;

	cur_node = lst_peek_first(buffer_lst);
	i = 0;
	while (cur_node->next != NULL)
	{
		value[i++] = *((char *)cur_node->content);
		cur_node = cur_node->next;
	}
	lst_clear(buffer_lst, NULL);
	lst_init(buffer_lst);
}

void	create_token(t_list *token_lst, t_list *buffer_lst, t_type type)
{
	t_token	*token;
	char	*value;

	token = (t_token *)ft_calloc(1, sizeof(t_token));
	value = (char *)ft_calloc(lst_size(buffer_lst), sizeof(char));
	copy_buffer(value, buffer_lst);
	token->value = value;
	token->type = type;
	lst_append(token_lst, new_node(&token));
}

int	get_env_len(char *line)
{
	int	env_len;

	env_len = 0;
	while (line[i])
}

void	expand(t_status *status, t_data *data, char **line, t_list *buffer_lst)
{
	char	*expanded_line;
	int		env_len;

	if (*(*line + 1) == '\0')
	{
		lst_append(buffer_lst, new_node(*line));
		(*line)++;
		return ;
	}
	env_len = get_env_len(*line);
	*line = expanded_line;
}
