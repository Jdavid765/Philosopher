/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:05:05 by canoduran         #+#    #+#             */
/*   Updated: 2026/02/01 13:50:28 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_free_all(t_prog *prog)
{
	if (!prog)
		return ;
	if (prog->mutex)
	{
		pthread_mutex_destroy(&prog->mutex[0]);
		free(prog->mutex);
		prog->mutex = NULL;
	}
	if (prog->philo)
	{
		free(prog->philo);
		prog->philo = NULL;
	}
}