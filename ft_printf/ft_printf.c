/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroux-fo <jroux-fo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:40:49 by jroux-fo          #+#    #+#             */
/*   Updated: 2021/12/24 15:24:13 by jroux-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parsing_2(va_list argptr, char c, int count)
{
	unsigned int			u;

	if (c == 's')
		count = ft_putstr(va_arg(argptr, char *), count);
	else if (c == 'c')
		count = count + ft_putchar(va_arg(argptr, int));
	else if (c == 'd' || c == 'i')
		count = ft_putnbr(va_arg(argptr, int), count);
	else if (c == 'X')
	{
		u = va_arg(argptr, int);
		count = ft_putnbr_base(u, "0123456789ABCDEF", count);
	}
	return (count);
}

int	ft_parsing(va_list argptr, char c, int count)
{
	unsigned long long int	p;
	unsigned int			u;

	if (c == 'u')
	{
		p = va_arg(argptr, unsigned int);
		count = ft_putnbr_base(p, "0123456789", count);
	}
	else if (c == 'p')
	{
		p = va_arg(argptr, unsigned long long int);
		count = ft_putstr("0x", count);
		count = ft_putnbr_base(p, "0123456789abcdef", count);
	}
	else if (c == 'x')
	{
		u = va_arg(argptr, int);
		count = ft_putnbr_base(u, "0123456789abcdef", count);
	}
	else if (c == '%')
		count = count + ft_putchar('%');
	else
		return (ft_parsing_2(argptr, c, count));
	return (count);
}

int	ft_skip_flag(char *str, int i)
{
	if (str[i])
	{
		if (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd'
			|| str[i] == 'i' || str[i] == 'u' || str[i] == 'x' || str[i] == 'X'
			|| str[i] == '%')
			return (i + 1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	argptr;

	i = 0;
	count = 0;
	va_start(argptr, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count = ft_parsing(argptr, format[i + 1], count);
			i = ft_skip_flag((char *)format, i + 1);
		}
		if (i < ft_strlen(format) && format[i] != '%')
		{
			count = count + ft_putchar(format[i]);
			i++;
		}
	}
	va_end(argptr);
	return (count);
}
