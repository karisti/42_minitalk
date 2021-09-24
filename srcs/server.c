/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:36:16 by karisti-          #+#    #+#             */
/*   Updated: 2021/09/21 12:05:05 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	handle_message(int sig)
{
	static char	chr = 0xFF;
	static int	desp = 0;

	if (sig == SIGUSR1)
		chr |= 128 >> desp;
	else if (sig == SIGUSR2)
		chr ^= 128 >> desp;
	desp++;
	if (desp == 8)
	{
		write(1, &chr, 1);
		chr = 0xFF;
		desp = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	if (pid < 0)
		exit_error("Error getting PID\n");
	ft_putstr("Server PID: ");
	ft_putnbr(pid);
	ft_putstr("\n");
	signal(SIGUSR1, handle_message);
	signal(SIGUSR2, handle_message);
	while (1)
		pause();
	return (0);
}
