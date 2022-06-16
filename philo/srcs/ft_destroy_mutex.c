/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:52:42 by msosnova          #+#    #+#             */
/*   Updated: 2022/01/12 20:52:47 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destroy_mutex(t_state *state, t_philo *philo)
{
	unsigned int	i;

	pthread_mutex_destroy(&state->ready_msg);
	pthread_mutex_destroy(&state->mutex_finish);
	pthread_mutex_destroy(&state->smn_eat);
	i = 0;
	while (i < state->n_philo)
	{
		pthread_mutex_destroy(&state->forks[i]);
		pthread_mutex_destroy(&philo[i].philo_eat);
		i++;
	}
}
