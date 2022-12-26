/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:33:59 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 12:15:41 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	**allocate_splited_str(char const *s, char c)
{
	char	**splited_str;
	size_t	word_count;

	word_count = 0;
	if (s == NULL)
		ft_exit("Error", STDERR_FILENO, EXIT_FAILURE);
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (*s != c)
		{
			word_count++;
			while (*s && *s != c)
				s++;
		}
		while (*s && *s == c)
			s++;
	}
	splited_str = (char **)ft_calloc((word_count + 1), sizeof(char *));
	return (splited_str);
}

static char	*cut_each_str(char const *s, char c)
{
	char	*str;
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	str = (char *)ft_calloc((i + 1), sizeof(char));
	i = 0;
	while (s[i] != c && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**splited_str;
	size_t	i;

	i = 0;
	splited_str = allocate_splited_str(s, c);
	while (*s && *s == c)
		s++;
	while (*s)
	{
		splited_str[i] = cut_each_str(s, c);
		while (*s != c && *s)
			s++;
		while (*s && *s == c)
			s++;
		i++;
	}
	splited_str[i] = NULL;
	return (splited_str);
}
