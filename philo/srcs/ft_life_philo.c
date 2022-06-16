/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:32:57 by msosnova          #+#    #+#             */
/*   Updated: 2022/01/12 17:33:02 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_ate_n_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->state->smn_eat);
	philo->state->n_philo_active--;
	if (philo->state->n_philo_active == 0)
	{
		ft_set_finish(philo);
		printf("Each philosopher ate %i time(s)\n", philo->state->n_must_eat);
	}
	pthread_mutex_unlock(&philo->state->smn_eat);
}	

void	ft_philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	ft_message(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	ft_message(philo, "has taken a fork");
	philo->last_eat = ft_time();
	ft_message(philo, "is eating");
	ft_msleep(philo, philo->state->time_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	ft_philo_sleep_think(t_philo *philo)
{
	ft_message(philo, "is sleeping");
	ft_msleep(philo, philo->state->time_sleep);
	ft_message(philo, "is thinking");
}

void	ft_thread_time_death(t_philo *philo)
{
	int	s;

	s = pthread_create(&philo->thread_id_timer, NULL, ft_timer_death, philo);
	if (s != 0)
	{
		ft_putstr("Fatal error");
		return ;
	}
	pthread_detach(philo->thread_id_timer);
}

void	*ft_life_philo(void *param)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)param;
	ft_thread_time_death(philo);
	philo->last_eat = ft_time();
	i = philo->state->n_must_eat;
	while (ft_get_finish(philo))
	{
		ft_philo_eat(philo);
		if (i > 0)
			i--;
		if (philo->state->n_must_eat != 0 && i == 0)
		{
			ft_ate_n_time(philo);
			break ;
		}
		ft_philo_sleep_think(philo);
	}
	return (NULL);
}
