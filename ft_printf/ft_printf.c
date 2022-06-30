/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okarakel <omerlutfu.k34@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:43:23 by okarakel          #+#    #+#             */
/*   Updated: 2022/02/11 14:32:23 by okarakel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_arg(va_list ar, char c)
{
	if (c == '%')
		return (ft_putchar_base('%', 0));
	else if (c == 'c')
		return (ft_putchar_base(va_arg(ar, int), 0));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_base(va_arg(ar, int), "0123456789"));
	else if (c == 's')
		return (ft_putstr(va_arg(ar, char *)));
	else if (c == 'p')
	{
		ft_putstr("0x");
		return (2 + ft_putptr_base(va_arg(ar, unsigned long int),
				"0123456789abcdef"));
	}
	else if (c == 'x')
		return (ft_putuns_base(va_arg(ar, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putuns_base(va_arg(ar, unsigned int), "0123456789ABCDEF"));
	else if (c == 'u')
		return (ft_putuns_base(va_arg(ar, unsigned int), "0123456789"));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	ar;
	int		size;
	int		i;

	va_start(ar, s);
	size = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			size += ft_arg(ar, s[i + 1]);
			i += 2;
			continue ;
		}
		else
			size += ft_putchar_base(s[i], 0);
		i++;
	}
	va_end(ar);
	return (size);
}
