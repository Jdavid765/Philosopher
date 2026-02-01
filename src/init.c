/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:01:54 by canoduran         #+#    #+#             */
/*   Updated: 2026/02/01 14:03:03 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init(t_prog *prog, char **av)
{
	int	i;

	i = 0;
	prog->nb_philo = atoi(av[0]);
	prog->philo = malloc(sizeof(t_philo) * prog->nb_philo);
	if (!prog->philo)
		ft_free_all(prog);
	prog->data.time_eat = atoi(av[2]);
	prog->data.time_thinks = 0;
	prog->data.time_sleep = atoi(av[3]);
	prog->data.time_dead = atoi(av[1]);
	prog->mutex = malloc(sizeof(pthread_mutex_t) * prog->nb_philo);
	if (!prog->mutex)
		ft_free_all(prog);
	while (i < prog->nb_philo)
	{
		pthread_mutex_init(&prog->mutex[i], NULL);
		prog->philo[i].threads = 0;
		i++;
		
	}
}
