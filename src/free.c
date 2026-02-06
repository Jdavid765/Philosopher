/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:05:05 by canoduran         #+#    #+#             */
/*   Updated: 2026/02/06 15:29:06 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_free_all(t_prog *prog)
{
	int	i;

	i = 0;
	if (!prog)
		return ;
	if (prog->fork)
	{
		while (i < prog->nb_philo)
		{
			pthread_mutex_destroy(&prog->fork[i]);
			i++;
		}
		free(prog->fork);
		prog->fork = NULL;
	}
	if (prog->philo)
	{
		free(prog->philo);
		prog->philo = NULL;
	}
}
