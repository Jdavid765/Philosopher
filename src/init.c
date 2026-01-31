/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:01:54 by canoduran         #+#    #+#             */
/*   Updated: 2026/01/31 13:36:58 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init(t_prog *prog, char **av)
{
	int	i;

	i = 0;
	prog->nb_philo = atoi(av[0]);
	prog->philo = malloc(prog->nb_philo);
	prog->data.time_eat = atoi(av[2]);
	prog->data.time_thinks = 0;
	prog->data.time_sleep = atoi(av[3]);
	prog->data.time_dead = atoi(av[1]);
	while (i < prog->nb_philo)
	{
		prog->philo[1].threads = NULL;
		i++;
	}
}
