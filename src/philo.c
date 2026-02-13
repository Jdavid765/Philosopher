/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:35:01 by david             #+#    #+#             */
/*   Updated: 2026/02/13 01:49:51 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	start_threads(t_prog *prog)
{
	int	i;

	i = 0;
	while (i < prog->nb_philo)
	{
		if (pthread_create(&prog->philo[i].threads,
				NULL, routine, &prog->philo[i]) != 0)
			return (-1);
		i++;
	}
	ft_supervisor(prog);
	i = 0;
	while (i < prog->nb_philo)
	{
		pthread_join(prog->philo[i].threads, NULL);
		i++;
	}
	return (0);
}

int	ft_philo(t_prog *prog)
{
	if (start_threads(prog) == -1)
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	t_prog	prog;

	if (ac == 6 || ac == 5)
	{
		if (parsing(&prog, av + 1, ac) == -1)
			return (ft_free_all(&prog), -1);
		if (ft_philo(&prog) == -1)
			return (ft_free_all(&prog), -1);
		ft_free_all(&prog);
	}
	else
		printf("Use: nb_philo, t_die, t_eat, t_sleep, nb_eat\n");
	return (0);
}
