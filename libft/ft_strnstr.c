/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:16:24 by grverdya          #+#    #+#             */
/*   Updated: 2024/01/28 16:05:20 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_needle;

	len_needle = ft_strlen(needle);
	i = 0;
	if (!needle[i] || (!haystack && len == 0))
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] && haystack[i + j] && i + j < len
			&& haystack[i + j] == needle[j])
			j++;
		if (j == len_needle)
			return ((char *) haystack + i);
		i++;
	}
	return (NULL);
}
