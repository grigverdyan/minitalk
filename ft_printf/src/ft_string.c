/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:34:27 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/14 19:34:28 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*strchr_42(const char *s, int c)
{
	while (*s != '\0')
	{
		if ((unsigned char) *s == (unsigned char) c)
			return ((char *) s);
		s++;
	}
	if (c == '\0')
		return ((char *) s);
	return (NULL);
}

size_t	putchar_42(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	putstr_42(char *s)
{
	size_t	len;

	if (!s)
		return (putstr_42("(null)"));
	len = strlen_42(s);
	write(1, s, len);
	return (len);
}

size_t	strlen_42(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		++len;
	return (len);
}
