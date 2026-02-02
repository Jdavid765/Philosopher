/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:35:01 by david             #+#    #+#             */
/*   Updated: 2026/02/02 18:43:35 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int mail = 0;

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
	return (NULL);
}

int	ft_philo(t_prog *prog)
{
	if (pthread_create(&prog->philo[0].threads, NULL, routine, prog) != 0)
		return (-1);
	if (pthread_create(&prog->philo[1].threads, NULL, routine, prog) != 0)
		return (-1);
	pthread_join(prog->philo[0].threads, NULL);
	pthread_join(prog->philo[1].threads, NULL);
	return (0);
}

int main(int ac, char **av)
{
	t_prog	prog;

	if (ac == 6)
	{
		if (parsing(&prog, av + 1) == -1)
			return (ft_free_all(&prog), -1);
		if (ft_philo(&prog) == -1)
			return (ft_free_all(&prog), -1);
		ft_free_all(&prog);
	}
	else
		printf("Use the command with this: nb_philosophers, t_die, t_eat, t_sleep, nb_eat\n");
	printf("%d\n", mail);
	return (0);
}