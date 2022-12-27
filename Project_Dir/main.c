/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:53:59 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/27 10:48:33 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lexer2.h"

void	del(void *content)
{
	const t_token	*token = content;

	ft_free(token->value);
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
		make_token_list2(&data, line);
		print_token_list(&data.token_lst);
		lst_clear(&data.token_lst, del);
	}
	return (0);
}
