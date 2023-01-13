/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:38:14 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLLIST_H
# define DLLIST_H

# include "../../libft/includes/libft.h"

typedef struct s_node
{
	void			*content;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

// head and tail is dummy node
typedef struct s_list
{
	int		size;
	t_node	*head;
	t_node	*tail;
}	t_list;

// list_utils.c
void	list_init(t_list *list);
t_node	*new_node(void *content);
int		list_isempty(t_list *list);
int		list_size(t_list *list);

// list_add.c
void	list_prepend(t_list *list, t_node *new_node);
void	list_append(t_list *list, t_node *new_node);

// list_peek.c
t_node	*list_peek_first_node(t_list *list);
t_node	*list_peek_last_node(t_list *list);
void	*list_peek_first_content(t_list *list);
void	*list_peek_last_content(t_list *list);

// list_delete.c
void	list_delete(t_node *node, void (*del)(void *));
void	list_delete_first(t_list *list, void (*del)(void *));
void	list_delete_last(t_list *list, void (*del)(void *));
void	list_clear(t_list *list, void (*del)(void *));

#endif
