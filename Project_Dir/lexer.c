/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:17:47 by junlee2           #+#    #+#             */
/*   Updated: 2022/12/26 16:43:40 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lexer.h"
#include "libraries/doubly_linked_list/includes/doubly_linked_list.h"
#include "libraries/libft/includes/libft.h"
#include <stdlib.h>

void	lex_make_token2(t_list *buffer, t_type type)
{
	
}

void	lex_addbuff(t_list *buffer, void *data)
{
	t_node	*node;

	node = new_node(data);
	if (!node)
		exit(EXIT_FAILURE);
	lst_append(buffer, node);
}

void	lex_less2(char **line, t_list *buffer)
{
	lex_addbuff(buffer, *line);
	(*line)++;
	if ('<' == **line)
	{
		lex_addbuff(buffer, *line);
		(*line)++;
	}
	return (lex_make_token2(buffer, REDIRECT));
}

void	lex_great2(char **line, t_list *buffer)
{
	lex_addbuff(buffer, *line);
	(*line)++;
	if ('>' == (*line)[1])
	{
		lex_addbuff(buffer, *line);
		(*line)++;
	}
	return (lex_make_token2(buffer, REDIRECT));
}

void	lex_pipe2(char **line, t_list *buffer)
{
	lex_addbuff(buffer, *line);
	(*line)++;
	return (lex_make_token2(buffer, REDIRECT));
}

void	lex_quote2(char **line, t_list *buffer)
{
	while ('\'' != **line && **line)
	{
		(*line)++;
		lex_addbuff(buffer, *line);
	}
	return (lex_make_token2(buffer, WORD));
}

void	lex_dquote2(char **line, t_list *buffer)
{
	while ('\"' != **line && **line)
	{
		(*line)++;
		lex_addbuff(buffer, *line);
	}
	return (lex_make_token2(buffer, WORD));
}

void	lex_start2(char **line, t_list *buffer)
{
	if ('<' == **line)
		return (lex_less2(line, buffer));
	else if ('>' == **line)
		return (lex_great2(line, buffer));
	else if ('|' == **line)
		return (lex_pipe2(line, buffer));
	else if ('\'' == **line)
		return (lex_quote2(line, buffer));
	else if ('\"' == **line)
		return (lex_dquote2(line, buffer));
	else
		return (void);
}

void	make_token_list(t_data *data, char *line)
{
	t_list	buffer;

	lex_start2(&line, &buffer);
}
