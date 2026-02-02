/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:05:05 by canoduran         #+#    #+#             */
/*   Updated: 2026/02/02 18:50:15 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_free_all(t_prog *prog)
{
	int	i;

	i = 0;
	if (!prog)
		return ;
	if (prog->mutex)
	{
		while (i < prog->nb_philo)
		{
			pthread_mutex_destroy(&prog->mutex[i]);
			i++;
		}
		free(prog->mutex);
		prog->mutex = NULL;
	}
	if (prog->philo)
	{
		free(prog->philo);
		prog->philo = NULL;
	}
}
