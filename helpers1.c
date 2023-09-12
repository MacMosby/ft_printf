/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:42:07 by mrodenbu          #+#    #+#             */
/*   Updated: 2023/07/12 14:44:34 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

long int	ft_strlen(const char *s)
{
	long int	i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_base(int n, char *base)
{
	long int	nbr;
	long int	i;
	int			count;

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
		count += ft_putnbr_base(nbr / i, base);
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

int	ft_putnbr_unsigned(unsigned int n)
{
	unsigned long int	nbr;
	int					count;

	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
		count++;
	}
	if (nbr > 9)
	{
		count += ft_putnbr_unsigned(nbr / 10);
		ft_putchar((nbr % 10) + 48);
		count++;
	}
	else
	{
		ft_putchar(nbr + 48);
		count++;
	}
	return (count);
}
/*
int main()
{
	ft_putnbr_base(-52, "0123456789ABCDEF");
	printf("%x", -52);
}
*/
