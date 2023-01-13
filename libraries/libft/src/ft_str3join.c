/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str3join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:58:18 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_str3join(char const *s1, char const *s2, char const *s3)
{
	char	*joined_str;
	char	*temp_str;

	temp_str = ft_strjoin(s1, s2);
	joined_str = ft_strjoin(temp_str, s3);
	free(temp_str);
	return (joined_str);
}
