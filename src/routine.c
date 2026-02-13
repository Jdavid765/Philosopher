/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 00:32:35 by canoduran         #+#    #+#             */
/*   Updated: 2026/02/13 15:21:32 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_thinking(t_philo *philo)
{
	print_message("is thinking", philo);
}

void	ft_sleep(t_philo *philo)
{
	usleep(philo->data->time_sleep);
	print_message("Is sleeping", philo);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	print_message("take the fork left", philo);
	pthread_mutex_lock(philo->right_fork);
	print_message("taking the fork right", philo);
	pthread_mutex_lock(&philo->meal_lock);
	philo->nb_eat++;
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->meal_lock);
	print_message("Is eating", philo);
	usleep(philo->data->time_eat * 1000);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id_philo % 2 == 0)
		usleep(10);
	while (philo->data->routine_active)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_thinking(philo);
	}
	return (NULL);
}
