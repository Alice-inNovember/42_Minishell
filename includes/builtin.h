/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:01:01 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/13 12:37:53 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "data.h"

typedef enum e_bt_error_stat
{
	HOME_NOT = 0,
	MANY_ARG,
	CANT_CD,
	NOT_NUM_ARG,
	INVALID_ARG
}	t_bt_error_stat;

typedef int		(*t_builtin_fp)(char **, t_list *);

int				bt_echo(char **cmd_vector, t_list *envp_list);
int				bt_pwd(char **cmd_vector, t_list *envp_list);
int				bt_env(char **cmd_vector, t_list *envp_list);
int				bt_exit(char **cmd_vector, t_list *envp_list);
int				bt_cd(char **cmd_vector, t_list *envp_list);
int				bt_export(char **cmd_vector, t_list *envp_list);
int				bt_unset(char **cmd_vector, t_list *envp_list);

//builtin_util.c
void			builtin_init(t_list *builtin_list);
t_builtin_fp	builtin_find(t_list *builtin_list, char *key);
int				check_word_cnt(char **cmd_vector);
void			error_handler_for_bt(char *cmd, char *word, int status);
void			print_export(t_list *envp_list);

#endif
