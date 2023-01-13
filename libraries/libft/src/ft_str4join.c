/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str4join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:00:29 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/08 22:02:01 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_str4join(char const *s1, \
								char const *s2, char const *s3, char const *s4)
{
	char	*joined_str;
	char	*temp_str;

	temp_str = ft_str3join(s1, s2, s3);
	joined_str = ft_strjoin(temp_str, s4);
	free(temp_str);
	return (joined_str);
}
