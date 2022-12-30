/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:38:14 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/30 10:04:18 by minseok2         ###   ########.fr       */
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
void	lst_init(t_list *list);
t_node	*new_node(void *content);
int		lst_isempty(t_list *list);
int		lst_size(t_list *list);

// list_add.c
void	lst_prepend(t_list *list, t_node *new_node);
void	lst_append(t_list *list, t_node *new_node);

// list_peek.c
t_node	*lst_peek_first_node(t_list *list);
t_node	*lst_peek_last_node(t_list *list);
void	*lst_peek_first_content(t_list *list);
void	*lst_peek_last_content(t_list *list);

// list_delete.c
void	lst_delete(t_node **node, void (*del)(void **));
void	lst_delete_first(t_list *list, void (*del)(void **));
void	lst_delete_last(t_list *list, void (*del)(void **));
void	lst_clear(t_list *list, void (*del)(void **));

#endif
