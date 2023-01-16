/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:48:29 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/16 14:33:25 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data.h"

extern int	g_exit_status;

void	print_syntax_err(t_data *data)
{
	t_error	flag;

	flag = data->syntax_err_flag;
	if (flag == E_NONE)
		return ;
	g_exit_status = 258;
	if (flag == E_SINGLE_QUOTE)
		ft_putendl_fd("minishell: syntax error\
: unclosed quote", STDERR_FILENO);
	else if (flag == E_SINGLE_DQUOTE)
		ft_putendl_fd("minishell: syntax error\
: unclosed dquote", STDERR_FILENO);
	else if (flag == E_NEAR_PIPE)
		ft_putendl_fd("minishell: syntax error\
 near unexpected token '|'", STDERR_FILENO);
	else if (flag == E_NEAR_LESS)
		ft_putendl_fd("minishell: syntax error\
 near unexpected token '<'", STDERR_FILENO);
	else if (flag == E_NEAR_GREAT)
		ft_putendl_fd("minishell: syntax error\
 near unexpected token '>'", STDERR_FILENO);
	else if (flag == E_NEAR_DGREAT)
		ft_putendl_fd("minishell: syntax error\
 near unexpected token '>>'", STDERR_FILENO);
	else if (flag == E_NEAR_DLESS)
		ft_putendl_fd("minishell: syntax error\
 near unexpected token '<<'", STDERR_FILENO);
	else if (flag == E_NEAR_NEWLINE)
		ft_putendl_fd("minishell: syntax error\
 near unexpected token 'newline'", STDERR_FILENO);
}
