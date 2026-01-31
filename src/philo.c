/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:35:01 by david             #+#    #+#             */
/*   Updated: 2026/01/31 13:29:31 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int mail = 0;

void	*routine(t_prog *prog)
{
	pthread_mutex_lock(&prog->mutex[0]);
	for(int i = 0; i < 1000000; i++)
	{
		mail++;
	}
	pthread_mutex_unlock(&prog->mutex[0]);
	return (NULL);
}

int	ft_philo(t_prog *prog)
{
	if (pthread_create(&prog->philo[0].threads, NULL, routine, NULL) != 0)
		return (-1);
	if (pthread_create(&prog->philo[1].threads, NULL, routine, NULL) != 0)
		return (-1);
	pthread_join(&prog->philo[0].threads, NULL);
	pthread_join(&prog->philo[1].threads, NULL);
	return (0);
}

int main(int ac, char **av)
{
	t_prog	prog;

	if (ac > 1)
	{
		init(&prog, av + 1);
		if (ft_philo(&prog) == -1)
			errors(&prog);
		ft_free_all(&prog);
	}
	printf("%d\n", mail);
	return (0);
}