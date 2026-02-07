/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:00:23 by canoduran         #+#    #+#             */
/*   Updated: 2026/02/07 12:44:32 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long int	ft_atoi(char *string)
{
	long	min;
	long	res;
	int	i;

	min = 1;
	res = 0;
	i = 0;
	while (string[i] == 32 || (string[i] >= 9 && string[i] <= 13))
		i++;
	
	if (string[i] == '+' || string[i] == '-')
	{
		if (string[i] == '-')
			min *= -1;
		i++;
	}
	while (string[i] >= 48 && string[i] <= 57)
	{
		res = res * 10 + (string[i] - '0');
		i++;
	}
	if (string[i] != '\0')
		return (201);
	return (res * min);
}

int	check_arg(t_prog *prog, char **av)
{
	prog->nb_philo = ft_atoi(av[0]);
	if (prog->nb_philo < 0 || prog->nb_philo > 200 || prog->nb_philo == 201)
		return (-1);
	prog->data.time_eat = ft_atoi(av[2]);
	if (prog->data.time_eat == 201)
		return (-1);
	prog->data.time_thinks = 0;
	prog->data.time_sleep = ft_atoi(av[3]);
	if (prog->data.time_sleep == 201)
		return (-1);
	prog->data.time_dead = ft_atoi(av[1]);
	if (prog->data.time_dead == 201)
		return (-1);
	return (0);
}

void	init_fork(t_prog *prog)
{
	int	i;

	i = 0;
	while (i < prog->nb_philo)
	{
		prog->data.fork[i] = 1;
		i++;
	}
}

int	init(t_prog *prog, char **av)
{
	int	i;

	i = 0;
	memset(prog, 0, sizeof(t_prog));
	if (check_arg(prog, av) == -1)	
		return (-1);
	prog->philo = malloc(sizeof(t_philo) * prog->nb_philo);
	if (!prog->philo)
		return (-1);
	prog->fork = malloc(sizeof(pthread_mutex_t) * prog->nb_philo);
	if (!prog->fork)
		return (-1);
	while (i < prog->nb_philo)
	{
		prog->philo[i].id_philo = i + 1;
		prog->philo[i].nb_eat = 0;
		pthread_mutex_init(&prog->fork[i], NULL);
		prog->philo[i].threads = 0;
		i++;
	}
	prog->data.fork = malloc (sizeof(int) * prog->nb_philo);
	if (!prog->data.fork)
		return (-1);
	init_fork(prog);
	return (0);
}

int	parsing(t_prog *prog, char **av)
{
	if (init(prog, av) == -1)
		return (printf("Errors\n"), -1);
	return (0);
}
