/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_export_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:06:54 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../includes/envp.h"
#include "../../includes/builtin.h"

char	**make_key_arr(t_list *envp_list)
{
	int		i;
	t_node	*cur_node;
	char	**key_arr;

	i = 0;
	key_arr = (char **)ft_calloc(list_size(envp_list) + 1, sizeof(char *));
	cur_node = list_peek_first_node(envp_list);
	while (cur_node->next)
	{
		key_arr[i] = ((t_envp *)cur_node->content)->key;
		cur_node = cur_node->next;
		i++;
	}
	key_arr[i] = 0;
	return (key_arr);
}

void	make_order_key_arr(char **key_arr)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (key_arr[i])
	{
		j = i + 1;
		while (key_arr[j])
		{	
			if (ft_strcmp(key_arr[i], key_arr[j]) > 0)
			{
				temp = key_arr[i];
				key_arr[i] = key_arr[j];
				key_arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	print_export(t_list *envp_list)
{
	char	**key_arr;
	int		i;
	char	*key;
	char	*value;

	i = 0;
	key_arr = make_key_arr(envp_list);
	make_order_key_arr(key_arr);
	while (key_arr[i])
	{
		key = key_arr[i];
		value = envp_find(envp_list, key);
		if (value)
			printf("declare -x %s=\"%s\"\n", key, value);
		else
			printf("declare -x %s\n", key);
		i++;
	}	
	free(key_arr);
}
