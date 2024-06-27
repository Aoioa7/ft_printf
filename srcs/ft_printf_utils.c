/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aichida <aichida@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:46:30 by aichida           #+#    #+#             */
/*   Updated: 2024/06/27 11:56:11 by aichida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// null guard

void	string(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (str[i] != '\0')
	{
		put_and_add(str[i], len);
		i++;
	}
}

// int_min -> other negative ->  positive

void	decimal_or_int(int n, int *len)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
	}
	else if (n < 0)
	{
		put_and_add('-', len);
		decimal_or_int(n * -1, len);
	}
	else
	{
		if (n >= 10)
			decimal_or_int(n / 10, len);
		put_and_add(n % 10 + '0', len);
	}
}

// use hex

void	pointer(unsigned long long p, int *len)
{
	write(1, "0x", 2);
	(*len) += 2;
	hexadecimal(p, len, 'x');
}

// unsigened long long = 2**8**8 = 16**16

void	hexadecimal(unsigned long long x, int *len, char c)
{
	char	str[16];
	char	*base;
	int		i;

	if (x == 0)
	{
		put_and_add('0', len);
		return ;
	}
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = 0;
	while (x != 0)
	{
		str[i] = base[x % 16];
		x /= 16;
		i++;
	}
	while (i--)
		put_and_add(str[i], len);
}

// no '-' no * no overflow

void	unsigned_int(unsigned int u, int *len)
{
	if (u >= 10)
		unsigned_int(u / 10, len);
	put_and_add(u % 10 + '0', len);
}
