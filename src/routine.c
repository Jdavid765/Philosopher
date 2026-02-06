/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 00:32:35 by canoduran         #+#    #+#             */
/*   Updated: 2026/02/06 15:29:32 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	mail = 0;

void	*routine(void *arg)
{
	t_prog	*prog;

	prog = (t_prog *)arg;
	pthread_mutex_lock(&prog->fork[0]);
	for(int i = 0; i < 1000000; i++)
	{
		mail++;
	}
	pthread_mutex_unlock(&prog->fork[0]);
	printf("%d\n", mail);
	return (NULL);
}
