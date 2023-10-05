/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:31:30 by mrodenbu          #+#    #+#             */
/*   Updated: 2023/07/17 14:22:28 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int			ft_printf(const char *s, ...);
int			ft_putchar(int c);
int			ft_putstr(char *s);
int			ft_putnbr_base(int n, char *base);
int			ft_putnbr_unsigned(unsigned int n);
int			ft_putnbr_hex(unsigned long long int n, char *base);
long int	ft_strlen(const char *s);
int			ft_putnbr_ptr(unsigned int n, char *base);
int			ft_formatter(int count, char format, va_list ap);

#endif
