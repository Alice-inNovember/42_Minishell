/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:44:41 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/04 12:51:06 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

void	del_s_token(void **content);
void	del_s_cmd(void **content);
void	del_s_redir(void **content);
void	del_s_proc_data(void **content);

void	print_syntax_err(t_data *data);

#endif
