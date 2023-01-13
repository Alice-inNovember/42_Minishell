/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:17:33 by junlee2           #+#    #+#             */
/*   Updated: 2023/01/11 11:57:01 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data.h"

char	*ft_strcat(char *dest, char *src)
{
	char	*temp;

	if (!src)
		return (dest);
	temp = dest;
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
	return (temp);
}

char	*str3join(char *str1, char *str2, char *str3)
{
	size_t	str1len;
	size_t	str2len;
	size_t	str3len;
	char	*returnstr;

	str3len = ft_strlen(str3);
	str1len = ft_strlen(str1);
	str2len = ft_strlen(str2);
	returnstr = (char *)ft_malloc(str1len + str2len + str3len + 1);
	if (!returnstr)
		return (0);
	returnstr[0] = 0;
	ft_strcat(returnstr, str1);
	ft_strcat(returnstr, str2);
	ft_strcat(returnstr, str3);
	return (returnstr);
}

char	**envp2arr(t_list *envp_list)
{
	size_t	i;
	size_t	envplen;
	char	**envparr;
	t_node	*node;
	t_envp	*envp_node;

	envplen = list_size(envp_list);
	envparr = (char **)ft_malloc(sizeof(char *) * (envplen + 1));
	node = list_peek_first_node(envp_list);
	i = 0;
	while (node->next != 0)
	{
		envp_node = (t_envp *)node->content;
		envparr[i] = str3join(envp_node->key, "=", envp_node->value);
		node = node->next;
		i++;
	}
	envparr[i] = NULL;
	return (envparr);
}

int	envp_exist(t_list *envp_list, char *key)
{
	t_node	*node;

	node = list_peek_first_node(envp_list);
	while (node->next)
	{
		if (!ft_strcmp(((t_envp *)node->content)->key, key))
			return (1);
		node = node->next;
	}
	return (0);
}
