/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:36:20 by karisti-          #+#    #+#             */
/*   Updated: 2021/11/26 18:45:48 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>

// libft.c
void	exit_error(char *str);
int		ft_strisnum(char *str);
int		ft_atoi(const char *str);
void	ft_putstr(char *s);
void	ft_putnbr(int n);

#endif
