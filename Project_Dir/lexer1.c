/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:53:59 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/27 10:44:07 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lexer1.h"

void	del(void *content)
{
	const t_token	*token = content;

	ft_free(token->value);
}

char	*merge_buffer(t_list *buffer_lst)
{
	char	*buffer;
	char	*c;
	t_node	*cur_node;
	int		i;

	buffer = (char *)ft_calloc(buffer_lst->size + 1, sizeof(char));
	cur_node = buffer_lst->head->next;
	i = 0;
	while (cur_node->next != NULL)
	{
		c = cur_node->content;
		buffer[i++] = *c;
		cur_node = cur_node->next;
	}
	lst_clear(buffer_lst, NULL);
	return (buffer);
}

void	make_token(t_list *token_lst, t_list *buffer_lst, t_type type)
{
	t_token	*token;

	token = (t_token *)ft_calloc(1, sizeof(t_token));
	token->type = type;
	if (type != T_WORD)
		token->value = NULL;
	else
		token->value = merge_buffer(buffer_lst);
	lst_append(token_lst, new_node(token));
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
	{
		lst_append(buffer_lst, new_node(*line));
		*status = LEX_WORD;
	}
	else
		ft_exit("Error: non printable character", STDERR_FILENO, EXIT_FAILURE);
	(*line)++;
}

void	lex_word(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst)
{
	if (ft_strchr(" |<>\'\"", **line))
	{
		make_token(token_lst, buffer_lst, T_WORD);
		*status = LEX_START;
	}
	else if (ft_isprint(**line))
	{
		lst_append(buffer_lst, new_node(*line));
		*status = LEX_WORD;
		(*line)++;
	}
	else
		ft_exit("Error: non printable character", STDERR_FILENO, EXIT_FAILURE);
}

void	lex_pipe(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst)
{
	(void)line;
	make_token(token_lst, buffer_lst, T_PIPE);
	*status = LEX_START;
}

void	lex_less(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst)
{
	if (**line == '<')
	{
		*status = LEX_DLESS;
		(*line)++;
	}
	else if (ft_isprint(**line))
	{
		make_token(token_lst, buffer_lst, T_LESS);
		*status = LEX_START;
	}
	else
		ft_exit("Error: non printable character", STDERR_FILENO, EXIT_FAILURE);
}

void	lex_dless(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst)
{
	(void)line;
	make_token(token_lst, buffer_lst, T_DLESS);
	*status = LEX_START;
}

void	lex_great(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst)
{
	if (**line == '>')
	{
		*status = LEX_DGREAT;
		(*line)++;
	}
	else if (ft_isprint(**line))
	{
		make_token(token_lst, buffer_lst, T_GREAT);
		*status = LEX_START;
	}
	else
		ft_exit("Error: non printable character", STDERR_FILENO, EXIT_FAILURE);
}

void	lex_dgreat(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst)
{
	(void)line;
	make_token(token_lst, buffer_lst, T_DGREAT);
	*status = LEX_START;
}

void	lex_quote(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst)
{
	if (**line == '\'')
	{
		make_token(token_lst, buffer_lst, T_WORD);
		*status = LEX_START;
		(*line)++;
	}
	else if (ft_isprint(**line))
	{
		lst_append(buffer_lst, new_node(*line));
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
		make_token(token_lst, buffer_lst, T_WORD);
		*status = LEX_START;
		(*line)++;
	}
	else if (ft_isprint(**line))
	{
		lst_append(buffer_lst, new_node(*line));
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
	if (type == T_WORD)
		printf("WORD");
	else if (type == T_QUOTE_WORD)
		printf("QUOTE_WORD");
	else if (type == T_DQUOTE_WORD)
		printf("DQUOTE_WORD");
	else if (type == T_PIPE)
		printf("PIPE");
	else if (type == T_LESS)
		printf("LESS");
	else if (type == T_GREAT)
		printf("GREAT");
	else if (type == T_DLESS)
		printf("DLESS");
	else if (type == T_DGREAT)
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
