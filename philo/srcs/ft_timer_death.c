/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timer_death.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:23:49 by msosnova          #+#    #+#             */
/*   Updated: 2022/01/12 17:23:59 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_timer_death(void *param)
{
	t_philo		*philo;
	t_time		t;
	t_time		t0;

	philo = (t_philo *)param;
	while (ft_get_finish(philo))
	{
		pthread_mutex_lock(&philo->philo_eat);
		t0 = philo->last_eat;
		pthread_mutex_unlock(&philo->philo_eat);
		if (ft_time() - t0 >= philo->state->time_death)
		{
			ft_set_finish(philo);
			usleep (300);
			t = ft_time() - philo->state->start_time;
			printf("%i %i %s\n", (int)t, philo->id, " is dead");
			break ;
		}
		usleep(100);
	}
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (NULL);
}
