/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:40:33 by mrodenbu          #+#    #+#             */
/*   Updated: 2023/07/17 14:32:16 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

#define HEX_UP "0123456789ABCDEF"
#define HEX_LOW "0123456789abcdef"

int	ft_print_pointer(va_list ap)
{
	unsigned long long int	num;
	int						count;

	count = 0;
	num = va_arg(ap, unsigned long long int);
	if (num == 0)
		count += ft_putstr("(nil)");
	else
	{
		count += ft_putstr("0x");
		count += ft_putnbr_hex(num, HEX_LOW);
	}
	return (count);
}

int	ft_formatter(int count, char format, va_list ap)
{
	if (format == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (format == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (format == 'p')
	{
		count += ft_print_pointer(ap);
	}
	else if (format == 'd' || format == 'i')
		count += ft_putnbr_base(va_arg(ap, int), "0123456789");
	else if (format == 'u')
		count += ft_putnbr_unsigned(va_arg(ap, unsigned int));
	else if (format == 'x')
		count += ft_putnbr_hex(va_arg(ap, unsigned int), HEX_LOW);
	else if (format == 'X')
		count += ft_putnbr_hex(va_arg(ap, unsigned int), HEX_UP);
	else if (format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	char					format;
	int						count;
	int						i;
	va_list					ap;

	count = 0;
	i = 0;
	va_start(ap, s);
	while (s[i] != 0)
	{
		if (s[i] == '%')
		{
			i++;
			format = s[i];
			count = ft_formatter(count, format, ap);
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
