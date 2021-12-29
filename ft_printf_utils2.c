/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:15:14 by sgmira            #+#    #+#             */
/*   Updated: 2021/12/11 14:20:32 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_putnbr(unsigned int nb)
{
	unsigned int	a;

	if (nb < 10)
	{
		ft_putchar(nb + 48);
	}
	else
	{
		ft_unsigned_putnbr(nb / 10);
		ft_unsigned_putnbr(nb % 10);
	}
	a = nb;
	return (len_u(a));
}

int	len_hexa(unsigned long int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		i++;
		nb /= 16;
	}
	return (i);
}

int	ft_putnbr_hex_low(unsigned int nb)
{
	int				j;
	int				tab[100];
	char			*base;
	unsigned int	a;

	a = nb;
	base = "0123456789abcdef";
	j = 0;
	if (nb == 0)
		ft_putchar(base[0]);
	while (nb)
	{
		tab[j] = nb % 16;
		nb = nb / 16;
		j++;
	}
	while (--j >= 0)
		ft_putchar(base[tab[j]]);
	return (len_hexa(a));
}

int	ft_putnbr_hex_up(unsigned int nb)
{
	int				j;
	int				tab[100];
	char			*baseup;
	unsigned int	a;

	a = nb;
	baseup = "0123456789ABCDEF";
	j = 0;
	if (nb == 0)
		ft_putchar(baseup[0]);
	while (nb)
	{
		tab[j] = nb % 16;
		nb = nb / 16;
		j++;
	}
	while (--j >= 0)
		ft_putchar(baseup[tab[j]]);
	return (len_hexa(a));
}

int	ft_putnbr_hex_p(void *s)
{
	int					j;
	int					tab[100];
	char				*base;
	unsigned long int	a;
	unsigned long int	b;

	a = (unsigned long int)s;
	b = a;
	base = "0123456789abcdef";
	j = 0;
	ft_putstr("0x");
	if (a == 0)
		ft_putchar(base[0]);
	while (a)
	{
		tab[j] = a % 16;
		a = a / 16;
		j++;
	}
	while (--j >= 0)
		ft_putchar(base[tab[j]]);
	return (len_hexa(b) + 2);
}
