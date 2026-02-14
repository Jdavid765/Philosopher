/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:05:05 by canoduran         #+#    #+#             */
/*   Updated: 2026/02/14 23:59:23 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	destroy_mutex(t_prog *prog)
{
	int	i;

	if (!prog || !prog->philo)
		return ;
	i = 0;
	pthread_mutex_destroy(&prog->data.print_lock);
	pthread_mutex_destroy(&prog->data.routine_lock);
	while (i < prog->nb_philo)
	{
		pthread_mutex_destroy(&prog->philo[i].left_fork);
		pthread_mutex_destroy(&prog->philo[i].meal_lock);
		i++;
	}
}

void	ft_free_all(t_prog *prog)
{
	if (!prog)
		return ;
	destroy_mutex(prog);
	if (prog->philo)
	{
		free(prog->philo);
		prog->philo = NULL;
		free(prog->all_philo_eat);
		prog->all_philo_eat = NULL;
	}
}
