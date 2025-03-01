/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:34:20 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/14 19:34:21 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"

#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	i;
	size_t	char_cnt;

	i = -1;
	char_cnt = 0;
	va_start(ap, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			if (strchr_42("cspdiuxX%", str[i]))
				char_cnt += ft_specifier(str[i], ap);
		}
		else
			char_cnt += putchar_42(str[i]);
	}
	va_end(ap);
	return (char_cnt);
}

size_t	ft_specifier(const char c, va_list ap)
{
	size_t	count;

	count = 0;
	if (c == '%')
		count += putchar_42('%');
	else if (c == 'c')
		count += putchar_42(va_arg(ap, int));
	else if (c == 's')
		count += putstr_42(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		count += config_specifier(va_arg(ap, int), "0123456789", c);
	else if (c == 'u')
		count += config_specifier(va_arg(ap, unsigned), "0123456789", c);
	else if (c == 'x')
		count += config_specifier(va_arg(ap, unsigned), "0123456789abcdef", c);
	else if (c == 'X')
		count += config_specifier(va_arg(ap, unsigned), "0123456789ABCDEF", c);
	else if (c == 'p')
		count += config_specifier(va_arg(ap, long), "0123456789abcdef", c);
	return (count);
}
