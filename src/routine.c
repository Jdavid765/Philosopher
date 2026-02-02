/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 00:32:35 by canoduran         #+#    #+#             */
/*   Updated: 2026/02/03 00:39:48 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	mail = 0;

void	*routine(void *arg)
{
	t_prog	*prog;

	prog = (t_prog *)arg;
	pthread_mutex_lock(&prog->mutex[0]);
	for(int i = 0; i < 1000000; i++)
	{
		mail++;
	}
	pthread_mutex_unlock(&prog->mutex[0]);
	printf("%d\n", mail);
	return (NULL);
}
