/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 00:32:35 by canoduran         #+#    #+#             */
/*   Updated: 2026/02/14 23:57:36 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_thinking(t_philo *philo)
{
	print_message("is thinking 🧠", philo);
}

void	ft_sleep(t_philo *philo)
{
	print_message("Is sleeping 😴", philo);
	usleep(philo->data->time_sleep * 1000);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	print_message("Has taken fork", philo);
	if (philo->nb_philo == 1)
	{
		usleep(philo->data->time_dead * 1000);
		stop_simulation(philo, NULL);
		pthread_mutex_unlock(&philo->left_fork);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	print_message("Has taken fork", philo);
	pthread_mutex_lock(&philo->meal_lock);
	philo->nb_eat++;
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->meal_lock);
	print_message("Is eating 🍝", philo);
	usleep(philo->data->time_eat * 1000);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int	check_routine_active(t_philo *philo)
{
	int	active;

	pthread_mutex_lock(&philo->data->routine_lock);
	active = philo->data->routine_active;
	pthread_mutex_unlock(&philo->data->routine_lock);
	return (active);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id_philo % 2 == 0)
		usleep(3);
	while (check_routine_active(philo))
	{
		ft_eat(philo);
		if (check_routine_active(philo) == 0)
			break ;
		ft_sleep(philo);
		if (check_routine_active(philo) == 0)
			break ;
		ft_thinking(philo);
	}
	return (NULL);
}
