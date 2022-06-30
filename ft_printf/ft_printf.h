/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okarakel <omerlutfu.k34@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:45:33 by okarakel          #+#    #+#             */
/*   Updated: 2022/02/11 14:32:10 by okarakel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_putnbr_base(int nb, char *base);
int	ft_putchar_base(int nb, char *b);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putuns_base(unsigned int nb, char *base);
int	ft_putptr_base(unsigned long int nb, char *base);
#endif