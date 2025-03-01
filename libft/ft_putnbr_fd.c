/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:22:55 by grverdya          #+#    #+#             */
/*   Updated: 2024/01/27 15:22:57 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	int	max;

	max = 1;
	if (nb < 0 && nb / 10 == 0)
		ft_putchar('-', fd);
	if (nb < 0)
		max = -1;
	if (nb / 10 != 0)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar(((nb % 10) * max) + '0', fd);
}
