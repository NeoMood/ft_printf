/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:05:23 by sgmira            #+#    #+#             */
/*   Updated: 2021/12/08 17:16:11 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
		return (i);
	}
	else
	{
		write(1, "(null)", 6);
		return (6);
	}
}

int	len(int nb)
{
	long	n;
	int		i;

	n = nb;
	i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	n /= 10;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n < 10)
	{
		ft_putchar(n + 48);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	n = nb;
	return (len(n));
}

int	len_u(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		i++;
	while (nb)
	{
		i++;
		nb /= 10;
	}
	return (i);
}
