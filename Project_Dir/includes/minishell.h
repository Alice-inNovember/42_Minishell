/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:32:30 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/06 10:42:12 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "data.h"
# include "envp.h"
# include "lexer.h"
# include "builtin.h"
# include "parser.h"
# include "util.h"
# include "executor.h"
# include "readline/readline.h"
# include "readline/history.h"
# include "../libraries/libft/includes/libft.h"
# include "../libraries/get_next_line/includes/get_next_line.h"

extern int	g_last_exit_status;

#endif
