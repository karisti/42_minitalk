/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:36:20 by karisti-          #+#    #+#             */
/*   Updated: 2021/09/17 13:56:47 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

# include <stdio.h>

void	exit_error(char *str);
int		ft_atoi(const char *str);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
int		ft_strisnum(char *str);
void	send_message(pid_t pid, char *message);
void	handle_message(int sig);
void	send_signal(pid_t pid, int sig);

#endif
