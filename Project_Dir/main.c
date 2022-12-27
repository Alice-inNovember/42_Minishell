/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:53:59 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/27 10:20:24 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lexer.h"
#include "libraries/doubly_linked_list/includes/doubly_linked_list.h"

void	del(void *content)
{
	const t_token	*token = content;

	ft_free(token->value);
}

void	make_token(t_list *token_lst, t_list *buffer_lst, t_type type)
{
	t_token	token;
	t_node	*cur_node;
	int		i;

	token.value = (char *)ft_calloc(buffer_lst->size, sizeof(char));
	cur_node = buffer_lst->head->next;
	i = 0;
	while (cur_node->next != NULL)
	{
		token.value[i++] = *(char *)(cur_node->content);
		token.type = type;
		lst_append(token_lst, new_node(&token));
		cur_node = cur_node->next;
	}
	lst_clear(buffer_lst, NULL);
}

void	lex_start(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst)
{
	(void)token_lst;
	if (**line == '\0')
	{
		*status = LEX_FINISH;
		return ;
	}
	lst_init(buffer_lst);
	if (**line == ' ')
		*status = LEX_START;
	else if (**line == '|')
		*status = LEX_PIPE;
	else if (**line == '<')
		*status = LEX_LESS;
	else if (**line == '>')
		*status = LEX_GREAT;
	else if (**line == '\'')
		*status = LEX_QUOTE;
	else if (**line == '\"')
		*status = LEX_DQUOTE;
	else if (ft_isprint(**line))
		*status = LEX_WORD;
	else
		ft_exit("Error: non printable character", STDERR_FILENO, EXIT_FAILURE);
	(*line)++;
}

void	lex_word(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst)
{
	if (ft_strchr(" |<>\'\"", **line))
	{
		make_token(token_lst, buffer_lst, WORD);
		*status = LEX_START;
	}
	else if (ft_isprint(**line))
	{
		lst_append(buffer_lst, new_node(line));
		*status = LEX_WORD;
		(*line)++;
	}
	else
		ft_exit("Error: non printable character", STDERR_FILENO, EXIT_FAILURE);
}

void	lex_pipe(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst)
{
	(void)line;
	make_token(token_lst, buffer_lst, PIPE);
	*status = LEX_START;
}

void	lex_less(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst)
{
	if (**line == '<')
	{
		lst_append(buffer_lst, new_node(line));
		*status = LEX_DLESS;
		(*line)++;
	}
	else if (ft_isprint(**line))
	{
		make_token(token_lst, buffer_lst, LESS);
		*status = LEX_START;
	}
	else
		ft_exit("Error: non printable character", STDERR_FILENO, EXIT_FAILURE);
}

void	lex_dless(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst)
{
	(void)line;
	make_token(token_lst, buffer_lst, DLESS);
	*status = LEX_START;
}

void	lex_great(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst)
{
	if (**line == '<')
	{
		lst_append(buffer_lst, new_node(line));
		*status = LEX_DLESS;
		(*line)++;
	}
	else if (ft_isprint(**line))
	{
		make_token(token_lst, buffer_lst, GREAT);
		*status = LEX_START;
	}
	else
		ft_exit("Error: non printable character", STDERR_FILENO, EXIT_FAILURE);
}

void	lex_dgreat(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst)
{
	(void)line;
	make_token(token_lst, buffer_lst, DGREAT);
	*status = LEX_START;
}

void	lex_quote(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst)
{
	if (**line == '\'')
	{
		make_token(token_lst, buffer_lst, WORD);
		*status = LEX_START;
		(*line)++;
	}
	else if (ft_isprint(**line))
	{
		lst_append(buffer_lst, new_node(line));
		*status = LEX_QUOTE;
		(*line)++;
	}
	else
		ft_exit("Error: non printable character", STDERR_FILENO, EXIT_FAILURE);
}

void	lex_dquote(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst)
{
	if (**line == '\"')
	{
		make_token(token_lst, buffer_lst, WORD);
		*status = LEX_START;
		(*line)++;
	}
	else if (ft_isprint(**line))
	{
		lst_append(buffer_lst, new_node(line));
		*status = LEX_DQUOTE;
		(*line)++;
	}
	else
		ft_exit("Error: non printable character", STDERR_FILENO, EXIT_FAILURE);
}

void	make_token_list(t_list *token_lst, char *line)
{
	t_lex_status			status;
	const t_lex_status_fp	lex_status_fp[TOTAL_LEX_STATUS - 1] = {
		lex_start, lex_word, lex_pipe, \
		lex_less, lex_dless, lex_great, lex_dgreat, \
		lex_quote, lex_dquote
	};
	t_list					buffer_lst;

	status = LEX_START;
	while (status != LEX_FINISH)
		(*lex_status_fp[status])(&status, token_lst, &line, &buffer_lst);
}

void	print_enum(t_type type)
{
	if (type == WORD)
		printf("WORD");
	else if (type == QUOTE_WORD)
		printf("QUOTE_WORD");
	else if (type == DQUOTE_WORD)
		printf("DQUOTE_WORD");
	else if (type == PIPE)
		printf("PIPE");
	else if (type == LESS)
		printf("LESS");
	else if (type == GREAT)
		printf("GREAT");
	else if (type == DLESS)
		printf("DLESS");
	else if (type == DGREAT)
		printf("DGREAT");
}

void	print_token_list(t_list *token_lst)
{
	t_node	*cur_node;
	t_token	*token;

	cur_node = token_lst->head->next;
	while (cur_node->next != NULL)
	{
		token = cur_node->content;
		printf("<token>\n");
		printf("token type = ");
		print_enum(token->type);
		printf("\ntoken value = %s\n\n", token->value);
		cur_node = cur_node->next;
	}
}

int	main(void)
{
	t_data	data;
	char	*line;

	while (1)
	{
		lst_init(&data.token_lst);
		line = readline("minishell>");
		//make_token_list(&data.token_lst, line);
		make_token_list2(&data, line);
		print_token_list(&data.token_lst);
		lst_clear(&data.token_lst, del);
	}
	return (0);
}
