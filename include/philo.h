/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:39:55 by david             #+#    #+#             */
/*   Updated: 2026/02/06 15:42:40 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>

typedef struct t_d
{
	int		time_eat;
	int		time_sleep;
	int		time_thinks;
	int		time_dead;
}	t_data;

typedef	struct t_philo
{
	int				id_philo;
	int				nb_eat;
	pthread_t		threads;
}	t_philo;

typedef	struct t_prog
{
	t_philo			*philo;
	t_data			data;
	pthread_mutex_t	*fork;
	long int		nb_philo;
}	t_prog;


void		ft_free_all(t_prog *prog);

long int	ft_atoi(char *string);
int			parsing(t_prog *prog, char **av);

void		*routine(void *arg);

#endif 