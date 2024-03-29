/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 20:03:51 by karisti-          #+#    #+#             */
/*   Updated: 2021/09/17 14:00:13 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	exit_error(char *str)
{
	ft_putstr(str);
	exit(1);
}

int	ft_strisnum(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		num;
	int		signo;
	long	i;

	num = 0;
	signo = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signo = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * signo);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}

void	ft_putnbr(int n)
{
	unsigned int	nb_1;

	if (n < 0)
	{
		ft_putstr("-");
		n = n * -1;
	}
	nb_1 = n;
	if (nb_1 >= 10)
	{
		ft_putnbr(nb_1 / 10);
	}
	nb_1 = nb_1 % 10 + '0';
	write(1, &nb_1, 1);
}
