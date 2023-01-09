/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:36:42 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/09 16:18:33 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVP_H
# define ENVP_H

# include "data.h"

void	envp_delete(t_list *envp_list, char *key);
void	envp_init(t_list *envp_list, char **envp);
void	envp_add(t_list *envp_list, char *key, char *value);
int		envp_exist(t_list *envp_list, char *key);
char	*envp_find(t_list *envp_list, char *key);
char	**envp2arr(t_list *envp_list);
char	*str3join(char *str1, char *str2, char *str3);
char	*ft_strcat(char *dest, char *src);

#endif
