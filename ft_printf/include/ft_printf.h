/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:34:01 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/14 19:34:02 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
size_t	ft_specifier(const char c, va_list ap);
size_t	config_specifier(ssize_t num, char *base, char sp);
size_t	ft_putnbr_base(ssize_t num, char *base);

#endif /* FT_PRINTF_H */
