/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supervisor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:17:08 by canoduran         #+#    #+#             */
/*   Updated: 2026/02/14 23:59:38 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	time_eat(t_philo *philo, t_prog *prog)
{
	int	meal;
	int	time;

	meal = 0;
	time = 0;
	pthread_mutex_lock(&philo->meal_lock);
	if (prog->flag_nb_eat == 1)
	{
		if (philo->nb_eat >= philo->data->nb_eat)
			meal = 1;
	}
	if (get_time() - philo->last_meal > philo->data->time_dead)
		time = 1;
	pthread_mutex_unlock(&philo->meal_lock);
	if (time == 1)
		return (1);
	else if (meal == 1)
		return (10);
	return (0);
}

int	all_eat(t_prog *prog)
{
	int	i;

	i = 0;
	while (i < prog->nb_philo)
	{
		if (prog->all_philo_eat[i] == 0)
			return (-1);
		i++;
	}
	return (0);
}

void	stop_simulation(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->data->routine_lock);
	philo->data->routine_active = 0;
	pthread_mutex_unlock(&philo->data->routine_lock);
	if (message)
	{
		pthread_mutex_lock(&philo->data->print_lock);
		printf("%s\n", message);
		pthread_mutex_unlock(&philo->data->print_lock);
	}
}

void	ft_supervisor(t_prog *prog)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (1)
	{
		if (i == prog->nb_philo)
			i = 0;
		result = time_eat(&prog->philo[i], prog);
		if (result == 1)
		{
			print_message("died", &prog->philo[i]);
			stop_simulation(&prog->philo[i], NULL);
			break ;
		}
		else if (result == 10)
			prog->all_philo_eat[i] = 1;
		if (prog->flag_nb_eat == 1 && all_eat(prog) == 0)
		{
			stop_simulation(&prog->philo[i], "All philosophers eat");
			break ;
		}
		i++;
	}
}
