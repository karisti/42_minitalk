/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:36:16 by karisti-          #+#    #+#             */
/*   Updated: 2021/09/17 13:47:08 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_signal(pid_t pid, int sig)
{
	if (kill(pid, sig) != 0)
		exit_error("Error: unable to kill\n");
}

void	send_message(pid_t pid, char *message)
{
	int	i;
	int	desp;

	i = 0;
	while (message[i])
	{
		desp = 0;
		while (desp < 8)
		{
			if (message[i] & 128 >> desp)
				send_signal(pid, SIGUSR1);
			else
				send_signal(pid, SIGUSR2);
			usleep(100);
			desp++;
		}
		i++;
	}	
}

int	main(int argc, char *argv [])
{
	pid_t	pid;

	if (argc != 3)
		exit_error("Error: Wrong arguments.\n");
	if (!ft_strisnum(argv[1]))
		exit_error("Error: Wrong PID\n");
	pid = ft_atoi(argv[1]);
	send_message(pid, argv[2]);
	send_message(pid, "\n");
	return (0);
}
