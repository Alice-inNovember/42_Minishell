/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:29:06 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/28 14:00:15 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/lexer1.h"

int	 main(int argc, char **argv, char **envp)
{
	t_data	data;
	char	*line;

	envp_init(&data, envp);
	while (1)
	{
		line = readline("minishell>");
		tokenize(&data.token_lst, line);
		print_token_lst(&data.token_lst);
	}
	return (0);
}
