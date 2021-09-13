/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:36:16 by karisti-          #+#    #+#             */
/*   Updated: 2021/09/13 21:27:53 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	handle_message(int sig)
{
	
	printf("handle message\n");
	sig++;
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	if (pid < 0)
		printf("Error getting PID\n");
	printf("Server PID: %i\n", pid);

	// MAGIA SIGNALS
	signal(SIGUSR1, handle_message);
	pause();
	return (0);
}
