/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:00:52 by msosnova          #+#    #+#             */
/*   Updated: 2022/01/12 17:01:43 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_time	ft_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_msleep(t_philo *philo, t_time time)
{
	t_time	time_0;

	time_0 = ft_time();
	while (philo->state->finish)
	{
		if (ft_time() - time_0 >= time)
			break ;
		usleep(5);
	}
}
