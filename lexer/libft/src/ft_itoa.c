/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:42:09 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 12:12:57 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	get_digits(int n)
{
	int	digits;

	digits = 1;
	if (n < 0)
		n *= -1;
	while (n > 9)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static char	*memory_allocate_num_str(int n)
{
	char	*num_str;
	int		digits;

	digits = get_digits(n);
	if (n < 0)
		num_str = (char *)ft_calloc((digits + 2), sizeof(char));
	else
		num_str = (char *)ft_calloc((digits + 1), sizeof(char));
	return (num_str);
}

static int	set_divider(int digits)
{
	int	divider;
	int	i;

	divider = 1;
	i = 1;
	while (i < digits)
	{
		divider *= 10;
		i++;
	}
	return (divider);
}

static void	convert_to_str(char *num_str, int n)
{
	int		divider;
	int		digit_num;

	divider = set_divider(get_digits(n));
	while (divider >= 1)
	{
		digit_num = n / divider;
		*num_str = digit_num + '0';
		n %= divider;
		divider /= 10;
		num_str++;
	}
	*num_str = '\0';
}

char	*ft_itoa(int n)
{
	char	*num_str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num_str = memory_allocate_num_str(n);
	if (num_str == NULL)
		return (NULL);
	if (n < 0)
	{
		*num_str = '-';
		n *= -1;
		convert_to_str(num_str + 1, n);
	}
	else
		convert_to_str(num_str, n);
	return (num_str);
}
