/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:35:01 by david             #+#    #+#             */
/*   Updated: 2026/01/30 01:44:55 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int mail = 0;

void	*routine(t_all *choose)
{
	pthread_mutex_lock(&choose->mutex[0]);
	for(int i = 0; i < 1000000; i++)
	{
		mail++;
	}
	pthread_mutex_unlock(&choose->mutex[0]);
	return (NULL);
}

int	philo(t_all *choose)
{
	if (pthread_create(&choose->philo.threads[0], NULL, routine(choose), NULL) == -1)
		return (-1);
	if (pthread_create(&choose->philo.threads[1], NULL, routine(choose), NULL) == -1)
		return (-1);
	pthread_join(&choose->philo.threads[0], NULL);
	pthread_join(&choose->philo.threads[1], NULL);
	return (0);
}

int main(int ac, char **av)
{
	t_all	choose;

	if (ac > 1)
	{
		init(&choose);
		if (philo(&choose) == -1)
			errors(&choose);
		ft_free_all(&choose);
	}
	printf("%d\n", mail);
	return (0);
}