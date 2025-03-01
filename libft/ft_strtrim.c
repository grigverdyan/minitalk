/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:20:04 by grverdya          #+#    #+#             */
/*   Updated: 2024/01/28 15:32:39 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	int		start;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	s1_len = ft_strlen(s1);
	start = 0;
	while (ft_strchr(set, s1[start]) && s1[start])
		++start;
	end = s1_len - 1;
	while (ft_strchr(set, s1[end]) && end >= start)
		--end;
	str = ft_substr(s1, start, end - start + 1);
	return (str);
}
