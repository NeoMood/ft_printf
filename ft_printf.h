/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:14:30 by sgmira            #+#    #+#             */
/*   Updated: 2021/12/09 12:20:28 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define  FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_putstr(char *str);
int		ft_putnbr(int nb);
char	*ft_strdup(const char *s1);
int		ft_putchar(char c);
int		len(int nb);
size_t	ft_strlen(const char *str);
int		ft_unsigned_putnbr(unsigned int nb);
int		ft_putnbr_hex_up(unsigned int nb);
int		ft_putnbr_hex_low(unsigned int nb);
int		ft_putnbr_hex_p(void *s);
int		ft_printf(const char *format, ...);
int		len_u(unsigned int nb);

#endif