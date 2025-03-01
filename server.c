/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:45:35 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/30 14:46:13 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft.h"
#include "ft_printf.h"

void	throw_error(const char *message)
{
	ft_printf("%s", message);
	exit(EXIT_FAILURE);
}

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	current_char;
	static int				bit_index;

	(void)context;
	current_char |= (signal == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		if (current_char == '\0')
		{
			ft_printf("\nServer PID: %d\n", getpid());
			if (kill(info->si_pid, SIGUSR1) < 0)
				throw_error("Error sending back signal to client!");
		}
		else
			ft_printf("%c", current_char);
		bit_index = 0;
		current_char = 0;
	}
	else
		current_char <<= 1;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 1)
	{
		ft_printf("Usage: %s ", argv[0]);
		exit(EXIT_FAILURE);
	}
	sa.sa_sigaction = &handle_signal;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	ft_printf("Server PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
