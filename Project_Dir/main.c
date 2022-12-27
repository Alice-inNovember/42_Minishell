/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:53:59 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/26 16:04:35 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lexer.h"

void	del(void *content)
{
	const t_token	*token = content;

	ft_free(token->value);
}

void	lex_start(t_lex_status *status, char **line, char **buffer)
{
	if (**line == '|')
		*status = LEX_PIPE;
	else if (**line == '<')
		*status = LEX_LESS;
	else if (**line == '>')
		*status = LEX_GREAT;
	else
	 	*status = LEX_WORD;
	line++;
}

void	lex_word(t_lex_status *status, char **line, char **buffer)
{
	if (**line == ' ')
		to_token(); // 임시
}

void	lex_pipe(t_lex_status *status, char **line, char **buffer)
{
	if (**line == '|')
		*status = LEX_PIPE;
	else if (**line == '<')
		*status = LEX_LESS;
	else if (**line == '>')
		*status = LEX_GREAT;
	else
	 	*status = LEX_WORD;
}

void	lex_less(t_lex_status *status, char **line, char **buffer)
{
	if (ft_strchr(const char *s, int c))
		*status = LEX_DLESS;
	else if (**line == ' ')
		*status = LEX_MAKE_TOKEN;
}

void	lex_dless(t_lex_status *status, char **line, char **buffer)
{

}

void	lex_great(t_lex_status *status, char **line, char **buffer)
{

}

void	lex_dgreat(t_lex_status *status, char **line, char **buffer)
{

}

void	lex_quote(t_lex_status *status, char **line, char **buffer)
{

}

void	lex_dquote(t_lex_status *status, char **line, char **buffer)
{

}

void	lex_make_token(t_lex_status *status, char **line, char **buffer)
{

}

void	lex_finish(t_lex_status *status, char **line, char **buffer)
{

}

void	make_token_list(t_data *data, char *line)
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
		(*lex_status_fp[status])(&status, &line, &buffer);
}

void	print_token_list(t_data *data)
{
	t_node	*cur_node;
	t_token	*token;

	cur_node = data->token_lst.head->next;
	while (cur_node->next != NULL)
	{
		token = cur_node->content;
		printf("<token>\ntoken type = %d\ntoken value = %s\n\n", token->type, token->value);
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
		make_token_list(&data, line);
		print_token_list(&data);
		lst_clear(&data.token_lst, del);
	}
	return (0);
}
