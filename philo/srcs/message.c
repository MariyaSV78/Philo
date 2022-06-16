/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:13:08 by msosnova          #+#    #+#             */
/*   Updated: 2022/01/12 17:14:15 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_message(t_philo *philo, char *s)
{
	t_time	t;

	t = ft_time() - philo->state->start_time;
	if (ft_get_finish(philo) == 0)
		return ;
	pthread_mutex_lock(&philo->state->ready_msg);
	printf("%i %i %s\n", (int)t, philo->id, s);
	pthread_mutex_unlock(&philo->state->ready_msg);
}
