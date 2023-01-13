/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:43:22 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define FREE_WITHOUT_LINE 0
# define FREE_WITH_LINE 1
# define JUST_COPY 0
# define COPY_AND_ADD_NUL 1

typedef struct s_glist
{
	int				fd;
	char			buf[BUFFER_SIZE];
	int				buf_len;
	int				printed_buf_len;
	struct s_glist	*next;
}	t_glist;

char	*get_next_line(int fd);
char	*str_join_from_remain(t_glist *node, int *total_len);
char	*make_line(t_glist **list, t_glist *node, char *line, int *total_len);
char	*str_join(t_glist *node, char *line, int *total_len);
char	*add_nul(t_glist **list, t_glist *node, char *line, int total_len);
t_glist	*set_current_node(t_glist **list, int fd);
char	*allocate_memory(t_glist *node, int buf_start_index, int total_len);
void	str_copy(char *joined_line, char *line, int total_len, int option);
char	*free_all(t_glist **list, t_glist *node, char *line, int option);

#endif
