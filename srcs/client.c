/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:36:16 by karisti-          #+#    #+#             */
/*   Updated: 2021/09/13 21:27:51 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_message(pid_t pid, char *message)
{
	printf("%s", message);
	kill(pid, SIGUSR1);
}

int	main(int argc, char *argv [])
{
	pid_t	pid;
	
	if (argc != 3)
		exit_error("Error: Wrong arguments\n");
	if (!strisnum(argv[1]))
		exit_error("Error: Wrong PID\n");
	pid = ft_atoi(argv[1]);

	printf("PID: %i\n", pid);
	send_message(pid, argv[2]);

	// MANDAR MENSAJES AL SERVER
	return (0);
}
