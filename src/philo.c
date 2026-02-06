/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:35:01 by david             #+#    #+#             */
/*   Updated: 2026/02/06 15:49:10 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_philo(t_prog *prog)
{
	int	i;

	i = 0;
	while (i < prog->nb_philo)
	{
		if (pthread_create(&prog->philo[i].threads, NULL, routine, prog) != 0)
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
		printf("Use command with this: nb_philo, t_die, t_eat, t_sleep, nb_eat\n");
	return (0);
}