/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aichida <aichida@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:45:58 by aichida           #+#    #+#             */
/*   Updated: 2024/06/30 13:46:06 by aichida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);

void	string(char *str, int *len);
void	decimal_or_int(int n, int *len);
void	pointer(unsigned long long p, int *len);
void	hexadecimal(unsigned long long x, int *len, char c);
void	unsigned_int(unsigned int u, int *len);

void	put_and_add(char c, int *len);

#endif
