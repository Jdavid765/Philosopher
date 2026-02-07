/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_pair.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 00:32:35 by canoduran         #+#    #+#             */
/*   Updated: 2026/02/07 12:45:51 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	mail = 0;

void	*take_fork(void *arg)
{
	t_prog	*prog;

	prog = (t_prog *)arg;
	pthread_mutex_lock(&prog->fork[0]);
	prog->data.fork[0] = 0;
	for(int i = 0; i < 1000000; i++)
	{
		mail++;
	}
	prog->data.fork[0] = 1;
	pthread_mutex_unlock(&prog->fork[0]);
	printf("%d\n", mail);
	return (NULL);
}

int	routine_pair(t_prog *prog)
{
	int	i;

	i = 0;
	while (i < prog->nb_philo)
	{
		if (pthread_create(&prog->philo[i].threads, NULL, take_fork, prog) != 0)
			return (-1);
		if (prog->data.fork[0] == 0)
			printf("can't take the fork\n");
		else
			printf("thinkings\n");
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
