/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:01:01 by junlee2           #+#    #+#             */
/*   Updated: 2022/12/29 15:51:17 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "data.h"

typedef void	(*t_builtin_fp)(char **, t_list *);

void			bt_echo(char **cmd_vector, t_list *envp_list);
void			bt_pwd(char **cmd_vector, t_list *envp_list);
void			bt_env(char **cmd_vector, t_list *envp_list);
void			bt_exit(char **cmd_vector, t_list *envp_list);
void			bt_cd(char **cmd_vector, t_list *envp_list);
void			bt_export(char **cmd_vector, t_list *envp_list);
void			bt_unset(char **cmd_vector, t_list *envp_list);

//builtin_util.c
void			builtin_init(t_list *builtin_lst);
t_builtin_fp	builtin_find(t_list *builtin_lst, char *key);

#endif