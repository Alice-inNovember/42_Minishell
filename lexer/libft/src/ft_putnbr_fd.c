/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:53:36 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 12:08:10 by minseok2         ###   ########.fr       */
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

static void	put_number(int n, int fd)
{
	int		divider;
	int		digit_num;
	char	char_digit_num;

	divider = set_divider(get_digits(n));
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	while (divider >= 1)
	{
		digit_num = n / divider;
		char_digit_num = digit_num + '0';
		write(fd, &char_digit_num, 1);
		n %= divider;
		divider /= 10;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
		put_number(n, fd);
}
