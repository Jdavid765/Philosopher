/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:39:55 by david             #+#    #+#             */
/*   Updated: 2026/01/30 19:15:25 by canoduran        ###   ########.fr       */
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
	int		time_eat;
	int		time_sleep;
	int		time_dead;
	t_data	data;
}	t_data;

typedef	struct t_philo
{
	int			*id_philo;
	pthread_t	*threads;
}	t_philo;

typedef struct t_al
{
	t_philo			*philo;
	pthread_mutex_t	*mutex;
}	t_all;

void	init(t_all *choose);
void	ft_free_all(t_all *choose);

#endif 