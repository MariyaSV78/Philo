/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:53:59 by msosnova          #+#    #+#             */
/*   Updated: 2022/01/12 20:54:04 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_set_finish(t_philo *philo)
{
	pthread_mutex_lock(&philo->state->mutex_finish);
	philo->state->finish = 0;
	pthread_mutex_unlock(&philo->state->mutex_finish);
}

int	ft_get_finish(t_philo *philo)
{
	int	finish;

	pthread_mutex_lock(&philo->state->mutex_finish);
	finish = philo->state->finish;
	pthread_mutex_unlock(&philo->state->mutex_finish);
	return (finish);
}
