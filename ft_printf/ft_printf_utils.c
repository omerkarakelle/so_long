/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okarakel <omerlutfu.k34@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:03:31 by okarakel          #+#    #+#             */
/*   Updated: 2022/02/11 14:33:08 by okarakel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	if (!s)
		return (ft_putstr("(null)"));
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	ft_putchar_base(int nb, char *b)
{
	if (b)
		ft_putchar_fd(b[nb], 1);
	else
		ft_putchar_fd(nb, 1);
	return (1);
}

int	ft_putptr_base(unsigned long int nb, char *base)
{
	unsigned long int	b;
	unsigned long int	a;

	b = ft_strlen(base);
	if (nb < b)
		return (ft_putchar_base(nb, base));
	else
	{
		a = 1 + ft_putptr_base(nb / b, base);
		ft_putchar_base((nb % b), base);
		return (a);
	}
}

int	ft_putuns_base(unsigned int nb, char *base)
{
	unsigned int	b;
	unsigned int	a;

	b = ft_strlen(base);
	if (nb < b)
		return (ft_putchar_base(nb, base));
	else
	{
		a = 1 + ft_putuns_base(nb / b, base);
		ft_putchar_base((nb % b), base);
		return (a);
	}
}

int	ft_putnbr_base(int nb, char *base)
{
	int	b;
	int	a;

	b = ft_strlen(base);
	if (nb == -2147483648)
	{
		a = ft_putnbr_base(nb / b, base);
		return (a + ft_putnbr_base(-(nb % b), base));
	}
	else if (nb < 0)
	{
		ft_putchar_base('-', 0);
		return (1 + ft_putnbr_base(-nb, base));
	}
	else if (nb < b)
		return (ft_putchar_base(nb, base));
	else
	{
		a = 1 + ft_putnbr_base(nb / b, base);
		ft_putchar_base((nb % b), base);
		return (a);
	}
}
