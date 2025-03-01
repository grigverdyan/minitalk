/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:12:43 by grverdya          #+#    #+#             */
/*   Updated: 2024/01/27 15:12:47 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*copy_dst;
	unsigned char	*copy_src;

	copy_dst = (unsigned char *)dst;
	copy_src = (unsigned char *)src;
	if (!copy_dst && !copy_src)
		return (NULL);
	if (copy_src > copy_dst)
		ft_memcpy(dst, src, len);
	else if (copy_src < copy_dst)
		while (len-- > 0)
			copy_dst[len] = copy_src[len];
	return (dst);
}
