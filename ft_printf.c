/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:39:52 by sgmira            #+#    #+#             */
/*   Updated: 2021/12/13 12:22:06 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversions(char a, va_list args)
{
	int	p;

	p = 0;
	if (a == 'c')
		p += ft_putchar(va_arg(args, int));
	else if (a == 's')
		p += ft_putstr(va_arg(args, char *));
	else if (a == 'd' || a == 'i')
		p += ft_putnbr(va_arg(args, int));
	else if (a == 'u')
		p += ft_unsigned_putnbr(va_arg(args, int));
	else if (a == 'X')
		p += ft_putnbr_hex_up(va_arg(args, int));
	else if (a == 'x')
		p += ft_putnbr_hex_low(va_arg(args, int));
	else if (a == 'p')
		p += ft_putnbr_hex_p(va_arg(args, void *));
	else if (a == '%')
		p += ft_putchar('%');
	else
		return (ft_putchar(a));
	return (p);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		p;
	va_list	args;

	va_start(args, format);
	i = 0;
	p = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			p++;
		}
		if (format[i] == '%')
		{
			i++;
			while (format[i] == ' ' && format[i])
				i++;
			p += conversions(format[i], args);
		}
		i++;
	}
	return (p);
}
