/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:34:36 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/30 14:45:19 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"

size_t	config_specifier(ssize_t num, char *base, char sp)
{
	size_t	count;

	count = 0;
	if (num < 0 && (sp == 'i' || sp == 'd' || sp == 'u'))
	{
		count += putchar_42('-');
		num *= -1;
	}
	else if (num == 0 && sp == 'p')
	{
		count += putstr_42("0x0");
		return (count);
	}
	else if (sp == 'p')
		count += putstr_42("0x");
	return (count + ft_putnbr_base(num, base));
}

size_t	ft_putnbr_base(ssize_t num, char *base)
{
	size_t	base_len;
	size_t	i;
	size_t	count;
	char	rev_str[42];

	base_len = strlen_42(base);
	count = 0;
	if (num == 0)
		count += putchar_42(base[0]);
	i = 0;
	while (num != 0)
	{
		rev_str[i] = base[num % base_len];
		num /= base_len;
		++i;
	}
	while (i-- != 0)
		count += putchar_42(rev_str[i]);
	return (count);
}
