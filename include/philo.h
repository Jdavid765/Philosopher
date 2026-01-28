/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:39:55 by david             #+#    #+#             */
/*   Updated: 2026/01/28 21:07:21 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

typedef struct t_d
{
	int	*fork;
	int	time_eat;
	int	time_sleep;
	int	time_thinks;
	int	time_dead;
}	t_data;

typedef struct t_al
{
	t_data	data;
}	t_all;

void	init(t_all *choose);

#endif 