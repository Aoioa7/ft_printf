/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aichida <aichida@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:46:37 by aichida           #+#    #+#             */
/*   Updated: 2024/06/27 12:15:51 by aichida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// different way by different key
// other keys not defined -> nothing happen -> next str[i]

static void	check(char c, va_list *args, int *len)
{
	if (c == 'c')
		put_and_add((char)va_arg(*args, int), len);
	else if (c == 's')
		string(va_arg(*args, char *), len);
	else if (c == 'p')
		pointer((unsigned long long)va_arg(*args, unsigned long), len);
	else if (c == 'd' || c == 'i')
		decimal_or_int(va_arg(*args, int), len);
	else if (c == 'u')
		unsigned_int(va_arg(*args, unsigned int), len);
	else if (c == 'x' || c == 'X')
		hexadecimal((unsigned long long)va_arg(*args, unsigned int), len, c);
	else if (c == '%')
		put_and_add('%', len);
	return ;
}

// ft_printf("xx%?xx%?xxx&?xx\n,a,b,c")

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	len = 0;
	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			check(str[i], &args, &len);
			i++;
		}
		else
		{
			put_and_add(str[i], &len);
			i++;
		}
	}
	va_end(args);
	return (len);
}

// test

// int	main(void)
// {

// 	return (0);
// }
