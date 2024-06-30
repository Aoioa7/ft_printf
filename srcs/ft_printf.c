/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aichida <aichida@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:46:37 by aichida           #+#    #+#             */
/*   Updated: 2024/06/30 13:51:45 by aichida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

// ... -> va_list -> linked list -> malloc, heap
// va_start -> move to next from str and set tmp
// va_arg -> return tmp and move to next
// no va_end -> memory leak!!

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

// cd ../ touch main.c -> copy and test this

// #include "ft_printf.h"
// #include "stdio.h"

// int	main(void)
// {
// 	char			*str;
// 	char			*empty;
// 	unsigned int	hex1;
// 	void			*hex2;
// 	int				limit;

// 	str = NULL;
// 	printf("%d\n", printf("%s\n", str));
// 	ft_printf("%d\n", ft_printf("%s\n", str));
// 	str = "world";
// 	empty = "";
// 	printf("%i\n", printf("hello%s%s\n", empty, str));
// 	ft_printf("%i\n", ft_printf("hello%s%s\n", empty, str));
// 	hex1 = 0x10AB;
// 	hex2 = &str;
// 	printf("%u\n", printf("%x%X\n", hex1, hex1));
// 	ft_printf("%u\n", ft_printf("%x%X\n", hex1, hex1));
// 	printf("%u\n", printf("%p\n", hex2));
// 	ft_printf("%u\n", ft_printf("%p\n", hex2));
// 	limit = -2147483648;
// 	printf("%d\n", printf("%d\n", limit));
// 	ft_printf("%d\n", ft_printf("%d\n", limit));

// 	return (0);
// }

//　not defined -> can't compile
// printf("\n%t\n", "unknown");
// ft_printf("\n%t\n", "unknown");
