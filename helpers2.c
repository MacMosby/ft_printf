/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:19:10 by mrodenbu          #+#    #+#             */
/*   Updated: 2023/07/17 13:47:56 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int	ft_putnbr_hex(unsigned long long int n, char *base)
{
	unsigned long long int	nbr;
	unsigned long long int	i;
	int						count;

	nbr = n;
	i = ft_strlen(base);
	count = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
		count++;
	}
	if (nbr > i - 1)
	{
		count += ft_putnbr_hex(nbr / i, base);
		write(1, &base[nbr % i], 1);
		count++;
	}
	else
	{
		write(1, &base[nbr], 1);
		count++;
	}
	return (count);
}

int	ft_putnbr_ptr(unsigned int n, char *base)
{
	unsigned int	nbr;
	long int		i;
	int				count;

	nbr = n;
	i = ft_strlen(base);
	count = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
		count++;
	}
	if (nbr > i - 1)
	{
		count += ft_putnbr_ptr(nbr / i, base);
		write(1, &base[nbr % i], 1);
		count++;
	}
	else
	{
		write(1, &base[nbr], 1);
		count++;
	}
	return (count);
}
/*
int main()
{
	printf("%lX\n", 4294967296 - 52);
	printf("%X\n", -52);
	ft_putnbr_hex(-52, "0123456789ABCDEF");
}
*/
