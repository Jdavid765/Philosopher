/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 21:02:52 by canoduran         #+#    #+#             */
/*   Updated: 2026/02/14 23:14:34 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_message(char *string, t_philo *philo)
{
	long int	timestamp;

	pthread_mutex_lock(&philo->data->routine_lock);
	if (!philo->data->routine_active)
	{
		pthread_mutex_unlock(&philo->data->routine_lock);
		return ;
	}
	pthread_mutex_unlock(&philo->data->routine_lock);
	pthread_mutex_lock(&philo->data->print_lock);
	timestamp = get_time() - philo->data->time_start;
	printf("[%ld], %s = %d\n", timestamp, string, philo->id_philo);
	pthread_mutex_unlock(&philo->data->print_lock);
}
