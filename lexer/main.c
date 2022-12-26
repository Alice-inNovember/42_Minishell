/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:53:59 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/26 12:33:13 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "readline/readline.h"
#include "readline/history.h"
#include "./get_next_line/includes/get_next_line.h"
#include "./doubly_linked_list/includes/doubly_linked_list.h"

// define lexer status
typedef enum e_lex_status
{
	LEX_START,
	LEX_WORD,
	LEX_PIPE,
	LEX_LESS,
	LEX_GREAT,
	LEX_DLESS,
	LEX_DGREAT,
	LEX_QUOTE,
	LEX_DQUOTE,
	LEX_MAKE_TOKEN,
	LEX_FINISH
}	t_lex_status;

#define TOTAL_LEX_STATUS	11

typedef void	(*t_lex_status_fp)();

// define token type as enum
typedef enum e_type
{
	WORD,
	PIPE,
	REDIRECT
}	t_type;

// define token as node
typedef struct s_token
{
	t_type	type;
	char	*value;
}	t_token;

// define redirect as enum
typedef enum e_redirect
{
	LESS,
	GREAT,
	DLESS,
	DGREAT
}	t_redirect;

// define command as node
typedef struct s_command
{
	char	**cmd_vector;
	t_list	infile_lst;
	t_list	outfile_lst;
}	t_command;

void	del(void *content)
{
	const t_token	*token = content;

	ft_free(token->value);
}

void	lex_start(char **line, char **buffer)
{

}

void	lex_word(char **line, char **buffer)
{

}

void	lex_pipe(char **line, char **buffer)
{

}

void	lex_less(char **line, char **buffer)
{

}

void	lex_dless(char **line, char **buffer)
{

}

void	lex_great(char **line, char **buffer)
{

}

void	lex_dgreat(char **line, char **buffer)
{

}

void	lex_quote(char **line, char **buffer)
{

}

void	lex_dquote(char **line, char **buffer)
{

}

void	lex_make_token(char **line, char **buffer)
{

}

void	lex_finish(char **line, char **buffer)
{

}

void	make_token_list(t_list *token_lst, char *line)
{
	t_lex_status			status;
	const t_lex_status_fp	lex_status_fp[TOTAL_LEX_STATUS] = {
		lex_start, lex_word, lex_pipe, \
		lex_less, lex_dless, lex_great, lex_dgreat, \
		lex_quote, lex_dquote, lex_make_token, lex_finish
	};
	char					*buffer;

	status = LEX_START;
	while (status != LEX_FINISH)
		(*lex_status_fp[status])(&line, &buffer);
}

void	print_token_list(t_list *token_lst)
{
	t_node	*cur_node;
	t_token	*token;

	cur_node = token_lst->head->next;
	while (cur_node->next != NULL)
	{
		token = cur_node->content;
		printf("<token>\ntoken type = %d\ntoken value = %s\n\n", token->type, token->value);
		cur_node = cur_node->next;
	}
}

int	main(void)
{
	t_list	token_lst;
	char	*line;

	while (1)
	{
		lst_init(&token_lst);
		line = readline("minishell>");
		make_token_list(&token_lst, line);
		print_token_list(&token_lst);
		lst_clear(&token_lst, del);
	}
	return (0);
}
