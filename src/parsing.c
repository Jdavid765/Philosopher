/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:00:23 by canoduran         #+#    #+#             */
/*   Updated: 2026/02/15 00:01:48 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long int	ft_atoi(char *string)
{
	long	min;
	long	res;
	int		i;

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
	long	nb_philo;

	memset(prog, 0, sizeof(t_prog));
	nb_philo = ft_atoi(av[0]);
	if (nb_philo < 0 || nb_philo > 200)
		return (-1);
	prog->nb_philo = nb_philo;
	prog->data.time_eat = ft_atoi(av[2]);
	if (prog->data.time_eat == 201)
		return (-1);
	prog->data.time_sleep = ft_atoi(av[3]);
	if (prog->data.time_sleep == 201)
		return (-1);
	prog->data.time_dead = ft_atoi(av[1]);
	if (prog->data.time_dead == 201)
		return (-1);
	prog->data.routine_active = 1;
	prog->all_philo_eat = malloc(sizeof(int) * prog->nb_philo);
	if (!prog->all_philo_eat)
		return (-1);
	return (0);
}

void	init_mutex(t_prog *prog)
{
	int	i;
	int	id_right;

	i = 0;
	id_right = 0;
	while (i < prog->nb_philo)
	{
		pthread_mutex_init(&prog->philo[i].left_fork, NULL);
		i++;
	}
	i = 0;
	while (i < prog->nb_philo)
	{
		id_right = (i + 1) % prog->nb_philo;
		prog->philo[i].right_fork = &prog->philo[id_right].left_fork;
		i++;
	}
}

int	init(t_prog *prog, char **av)
{
	int	i;

	if (check_arg(prog, av) == -1)
		return (-1);
	prog->philo = malloc(sizeof(t_philo) * prog->nb_philo);
	if (!prog->philo)
		return (-1);
	i = 0;
	while (i < prog->nb_philo)
	{
		prog->philo[i].id_philo = i + 1;
		prog->philo[i].nb_eat = 0;
		prog->philo[i].nb_philo = prog->nb_philo;
		prog->philo[i].data = &prog->data;
		prog->philo[i].threads = 0;
		pthread_mutex_init(&prog->philo[i].meal_lock, NULL);
		i++;
	}
	init_mutex(prog);
	pthread_mutex_init(&prog->data.print_lock, NULL);
	pthread_mutex_init(&prog->data.routine_lock, NULL);
	return (0);
}

int	parsing(t_prog *prog, char **av, int ac)
{
	int	i;

	i = 0;
	if (init(prog, av) == -1)
		return (printf("Errors\n"), -1);
	if (ac == 6)
	{
		prog->flag_nb_eat = 1;
		prog->data.nb_eat = ft_atoi(av[4]);
		if (prog->data.nb_eat == 201)
			return (-1);
	}
	else
		prog->data.nb_eat = -1;
	prog->data.time_start = get_time();
	while (i < prog->nb_philo)
	{
		prog->all_philo_eat[i] = 0;
		prog->philo[i].last_meal = get_time();
		i++;
	}
	return (0);
}
