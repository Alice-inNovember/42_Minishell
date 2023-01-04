/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:48:29 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/04 13:32:07 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_syntax_err(t_data *data)
{
	t_error	flag;

	flag = data->syntax_err_flag;
	if (flag == E_NONE)
		return ;
	else if (flag == E_SINGLE_QUOTE)
		printf("minishell: syntax error: unclosed quote\n");
	else if (flag == E_SINGLE_DQUOTE)
		printf("minishell: syntax error: unclosed dquote\n");
	else if (flag == E_NEAR_PIPE)
		printf("minishell: syntax error near unexpected token '|'\n");
	else if (flag == E_NEAR_LESS)
		printf("minishell: syntax error near unexpected token '<'\n");
	else if (flag == E_NEAR_GREAT)
		printf("minishell: syntax error near unexpected token '>'\n");
	else if (flag == E_NEAR_DGREAT)
		printf("minishell: syntax error near unexpected token '>>'\n");
	else if (flag == E_NEAR_DLESS)
		printf("minishell: syntax error near unexpected token '<<'\n");
	else if (flag == E_NEAR_NEWLINE)
		printf("minishell: syntax error near unexpected token 'newline'\n");
}
