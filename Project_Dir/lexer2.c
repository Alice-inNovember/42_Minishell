/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:17:47 by junlee2           #+#    #+#             */
/*   Updated: 2022/12/27 10:41:51 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lexer2.h"
#include "libraries/doubly_linked_list/includes/doubly_linked_list.h"
#include "libraries/libft/includes/libft.h"
#include <stdlib.h>

void	lex_make_token2(t_list *buffer, t_type type, t_list *token_lst)
{
	t_node	*buf;
	t_token	*token;
	char	*str;
	int		i;

	buf = buffer->head->next;
	str = (char *)ft_malloc(lst_size(buffer) + 1);
	i = 0;
	while (buf->next != NULL)
	{
		str[i] = *(char *)buf->content;
		i++;
		buf = buf->next;
	}
	str[i] = 0;
	token = ft_calloc(1, sizeof(t_token));
	token->type = type;
	token->value = str;
}

void	lex_addbuff(t_list *buffer, void *value)
{
	t_node	*node;

	node = new_node(value);
	lst_append(buffer, node);
}

void	lex_less2(char **line, t_list *buffer, t_list *token_lst)
{
	lex_addbuff(buffer, *line);
	(*line)++;
	if ('<' == **line)
	{
		lex_addbuff(buffer, *line);
		(*line)++;
		return (lex_make_token2(buffer, T_DLESS, token_lst));
	}
	return (lex_make_token2(buffer, T_LESS, token_lst));
}

void	lex_great2(char **line, t_list *buffer, t_list *token_lst)
{
	lex_addbuff(buffer, *line);
	(*line)++;
	if ('>' == (*line)[1])
	{
		lex_addbuff(buffer, *line);
		(*line)++;
		return (lex_make_token2(buffer, T_GREAT, token_lst));
	}
	return (lex_make_token2(buffer, T_DGREAT, token_lst));
}

void	lex_pipe2(char **line, t_list *buffer, t_list *token_lst)
{
	lex_addbuff(buffer, *line);
	(*line)++;
	return (lex_make_token2(buffer, T_PIPE, token_lst));
}

void	lex_quote2(char **line, t_list *buffer, t_list *token_lst)
{
	(*line)++;
	while ('\'' != **line && **line)
	{
		lex_addbuff(buffer, *line);
		(*line)++;
	}
	(*line)++;
	return (lex_make_token2(buffer, T_WORD, token_lst));
}

void	lex_dquote2(char **line, t_list *buffer, t_list *token_lst)
{
	(*line)++;
	while ('\"' != **line && **line)
	{
		lex_addbuff(buffer, *line);
		(*line)++;
	}
	(*line)++;
	return (lex_make_token2(buffer, T_WORD, token_lst));
}

void	lex_word2(char **line, t_list *buffer, t_list *token_lst)
{
	while (!ft_strchr("<>|\'\" ", **line) && **line)
	{
		lex_addbuff(buffer, *line);
		(*line)++;
	}
	return (lex_make_token2(buffer, T_WORD, token_lst));
}

void	make_token_list2(t_data *data, char *line)
{
	t_list	buffer;

	while (*line)
	{
		lst_init(&buffer);
		if ('<' == *line)
			lex_less2(&line, &buffer, &data->token_lst);
		else if ('>' == *line)
			lex_great2(&line, &buffer, &data->token_lst);
		else if ('|' == *line)
			lex_pipe2(&line, &buffer, &data->token_lst);
		else if ('\'' == *line)
			lex_quote2(&line, &buffer, &data->token_lst);
		else if ('\"' == *line)
			lex_dquote2(&line, &buffer, &data->token_lst);
		else
			lex_word2(&line, &buffer, &data->token_lst);
		ft_putstr_fd("start\n", 1);
		lst_clear(&buffer, NULL);
		ft_putstr_fd("end\n", 1);
	}
}
