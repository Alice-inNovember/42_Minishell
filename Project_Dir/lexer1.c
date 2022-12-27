/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:53:59 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/27 15:17:56 by minseok2         ###   ########.fr       */
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
	t_node	*cur_node;
	int		i;

	buffer = (char *)ft_calloc(buffer_lst->size + 1, sizeof(char));
	cur_node = buffer_lst->head->next;
	i = 0;
	while (cur_node->next != NULL)
	{
		buffer[i++] = *(char *)(cur_node->next);
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

void	start(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst)
{
	(void)token_lst;
	if (**line == '\0')
	{
		*status = FINISH;
		return ;
	}
	lst_init(buffer_lst);
	if (**line == ' ')
		*status = START;
	else if (**line == '|')
		*status = MAKE_PIPE;
	else if (**line == '<')
		*status = MAKE_LESS;
	else if (**line == '>')
		*status = MAKE_GREAT;
	else if (**line == '\'')
		*status = QUOTE_OPEN;
	else if (**line == '\"')
		*status = DQUOTE_OPEN;
	else if (ft_isprint(**line))
	{
		lst_append(buffer_lst, new_node(*line));
		*status = MAKE_WORD;
	}
	else
		ft_exit("Error: non printable character", STDERR_FILENO, EXIT_FAILURE);
	(*line)++;
}

void	make_word(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst)
{
	if (ft_strchr(" |<>\'\"", **line))
	{
		make_token(token_lst, buffer_lst, T_WORD);
		*status = START;
	}
	else if (ft_isprint(**line))
	{
		lst_append(buffer_lst, new_node(*line));
		*status = MAKE_WORD;
		(*line)++;
	}
	else
		ft_exit("Error: non printable character", STDERR_FILENO, EXIT_FAILURE);
}

void	make_pipe(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst)
{
	(void)line;
	make_token(token_lst, buffer_lst, T_PIPE);
	*status = START;
}

void	make_less(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst)
{
	if (**line == '<')
	{
		*status = MAKE_DLESS;
		(*line)++;
	}
	else if (ft_isprint(**line))
	{
		make_token(token_lst, buffer_lst, T_LESS);
		*status = START;
	}
	else
		ft_exit("Error: non printable character", STDERR_FILENO, EXIT_FAILURE);
}

void	make_dless(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst)
{
	(void)line;
	make_token(token_lst, buffer_lst, T_DLESS);
	*status = START;
}

void	make_great(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst)
{
	if (**line == '>')
	{
		*status = MAKE_DGREAT;
		(*line)++;
	}
	else if (ft_isprint(**line))
	{
		make_token(token_lst, buffer_lst, T_GREAT);
		*status = START;
	}
	else
		ft_exit("Error: non printable character", STDERR_FILENO, EXIT_FAILURE);
}

void	make_dgreat(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst)
{
	(void)line;
	make_token(token_lst, buffer_lst, T_DGREAT);
	*status = START;
}

void	quote_open(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst)
{
	if (**line == '\'')
	{
		*status = QUOTE_CLOSE;
		(*line)++;
	}
	else if (ft_isprint(**line))
	{
		lst_append(buffer_lst, new_node(*line));
		*status = QUOTE_OPEN;
		(*line)++;
	}
	else
		ft_exit("3Error: non printable character", STDERR_FILENO, EXIT_FAILURE);
}

void	quote_close(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst)
{
	if (**line == '\'')
	{
		*status = QUOTE_OPEN;
		(*line)++;
	}
	else if (**line == '\"')
	{
		*status = START;
		(*line)++;
	}
	else if (ft_isprint(**line))
	{
		make_token(token_lst, buffer_lst, T_WORD);
		*status = START;
	}
	else
		ft_exit("2Error: non printable character", STDERR_FILENO, EXIT_FAILURE);
}

void	dquote_open(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst)
{
	if (**line == '\"')
	{
		*status = DQUOTE_CLOSE;
		(*line)++;
	}
	else if (ft_isprint(**line))
	{
		lst_append(buffer_lst, new_node(*line));
		*status = DQUOTE_OPEN;
		(*line)++;
	}
	else
		ft_exit("1Error: non printable character", STDERR_FILENO, EXIT_FAILURE);
}

void	dquote_close(t_lex_status *status, t_list *token_lst, char **line, t_list *buffer_lst)
{
	printf("!!!!%c\n", **line);
	if (**line == '\'')
	{
		*status = QUOTE_OPEN;
		(*line)++;
	}
	else if (**line == '\"')
	{
		*status = START;
		(*line)++;
	}
	else if (ft_isprint(**line))
	{
		make_token(token_lst, buffer_lst, T_WORD);
		*status = START;
	}
	else
		ft_exit("0Error: non printable character", STDERR_FILENO, EXIT_FAILURE);
}

void	make_token_list(t_list *token_lst, char *line)
{
	t_lex_status			status;
	const t_lex_status_fp	lex_status_fp[TOTAL_LEX_STATUS - 1] = {
		start, make_word, make_pipe, \
		make_less, make_dless, make_great, make_dgreat, \
		quote_open, quote_close, dquote_open, dquote_close
	};
	t_list					buffer_lst;

	status = START;
	while (status != FINISH)
		(*lex_status_fp[status])(&status, token_lst, &line, &buffer_lst);
}

void	print_enum(t_type type)
{
	if (type == T_WORD)
		printf("WORD");
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
		printf("line = %s\nlen = %d\n", line, (int)ft_strlen(line));
		make_token_list(&data.token_lst, line);
		print_token_list(&data.token_lst);
		lst_clear(&data.token_lst, del);
	}
	return (0);
}
