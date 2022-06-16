/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:27:16 by msosnova          #+#    #+#             */
/*   Updated: 2022/01/12 17:27:28 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_start_thread(t_state *state, t_philo *philo)
{
	unsigned int	i;
	int				s;

	i = 0;
	state->start_time = ft_time();
	while (i < state->n_philo)
	{
		s = pthread_create(&philo[i].thread_id, NULL, ft_life_philo, philo + i);
		if (s != 0)
		{
			ft_putstr("Fatal error\n");
			return ;
		}
		usleep(100);
		i++;
	}
	i = 0;
	while (i < state->n_philo)
	{
		pthread_join(philo[i++].thread_id, NULL);
		usleep(100);
	}
}
