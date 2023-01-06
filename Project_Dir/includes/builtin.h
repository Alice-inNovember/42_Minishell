/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:01:01 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/06 09:33:37 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "data.h"
# include "../libraries/libft/includes/libft.h"
# include <sys/types.h>
# include <dirent.h>
# include "../libraries/dllist/includes/dllist.h"
# include <stdio.h>  
# include <readline/readline.h>
# include <readline/history.h>

typedef int	(*t_builtin_fp)(char **, t_list *);

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
#endif