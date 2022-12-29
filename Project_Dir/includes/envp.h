/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:36:42 by junlee2           #+#    #+#             */
/*   Updated: 2022/12/29 13:43:50 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVP_H
# define ENVP_H

# include "data.h"

void	envp_delete(t_list *envp_list, char *key);
void	envp_init(t_list *envp_list, char **envp);
void	envp_add(t_list *envp_list, char *key, char *value);
char	*envp_find(t_list *envp_list, char *key);
char	**get_envp(t_list *envp_list);

#endif
