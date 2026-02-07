/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:35:01 by david             #+#    #+#             */
/*   Updated: 2026/02/07 12:47:08 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_philo(t_prog *prog)
{
	// int	pair_impair;

	// pair_impair = prog->nb_philo % 2;
	if (routine_pair(prog) == -1)
		return (-1);
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