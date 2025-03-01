/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:15:16 by grverdya          #+#    #+#             */
/*   Updated: 2024/01/27 15:15:20 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*new;

	new = NULL;
	while (*s)
	{
		if ((char) *s == (char) c)
			new = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *) s);
	return (new);
}
