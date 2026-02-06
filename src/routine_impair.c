/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_impair.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 23:29:29 by canoduran         #+#    #+#             */
/*   Updated: 2026/02/06 23:50:35 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int		routine_impair(t_prog *prog)
{
	int	i;

	i = 0;
	while (i < prog->nb_philo)
	{
		if (pthread_create(&prog->philo[i].threads, NULL, take_fork, prog) != 0)
			return (-1);
		i++;
	}
	i = 0;
	while (i < prog->nb_philo)
	{
		pthread_join(prog->philo[i].threads, NULL);
		i++;
	}
	return (0);
}
