/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:30:23 by tyi               #+#    #+#             */
/*   Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#define POS	1
#define NEG	-1

static int	get_sign(char **string)
{
	if (**string == '-')
	{
		(*string)++;
		return (-1);
	}
	else if (**string == '+')
	{
		(*string)++;
		return (1);
	}
	else
		return (1);
}

int	ft_atoi(char *string)
{
	int				i;
	int				sign;
	unsigned long	number;

	i = 0;
	sign = get_sign(&string);
	if (string == NULL || *string == '\0')
		return (0);
	number = 0;
	while (ft_isspace(*string))
		string++;
	while (string[i])
	{
		if (!(ft_isdigit(string[i])))
			return (0);
		number *= 10;
		number += (string[i] - '0');
		if ((sign == POS && number > 2147483647) || \
				(sign == NEG && number > 2147483648))
			return (0);
		i++;
	}
	return ((int)(sign * number));
}
