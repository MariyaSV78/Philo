/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 20:02:18 by msosnova          #+#    #+#             */
/*   Updated: 2021/12/28 20:02:22 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_mutex(t_state *state)
{
	unsigned int	i;

	state->forks = malloc(state->n_philo * sizeof(t_mutex));
	if (!state->forks)
	{
		ft_putstr("Fatal error\n");
		return (0);
	}
	pthread_mutex_init(&state->ready_msg, NULL);
	pthread_mutex_init(&state->mutex_finish, NULL);
	pthread_mutex_init(&state->smn_eat, NULL);
	i = 0;
	while (i < state->n_philo)
		pthread_mutex_init(&state->forks[i++], NULL);
	return (1);
}

int	ft_init_data(int argc, char *argv[], t_state *state)
{
	state->n_philo = ft_atoi(argv[1]);
	state->time_death = ft_atoi(argv[2]);
	state->time_eat = ft_atoi(argv[3]);
	state->time_sleep = ft_atoi(argv[4]);
	state->n_philo_active = state->n_philo;
	if (argc == 6)
		state->n_must_eat = ft_atoi(argv[5]);
	else
		state->n_must_eat = 0;
	state->finish = 1;
	if (ft_init_mutex(state) == 0)
		return (0);
	return (1);
}

void	ft_init_philo(t_state *state, t_philo *philo)
{
	unsigned int	i;

	i = 0;
	while (i < state->n_philo)
	{
		philo[i].state = state;
		if (i % 2 == 0)
		{
			philo[i].left_fork = &state->forks[i];
			if (i == 0)
				philo[i].right_fork = &state->forks[state->n_philo - 1];
			else
				philo[i].right_fork = &state->forks[i - 1];
		}
		else
		{
			philo[i].left_fork = &state->forks[i - 1];
			philo[i].right_fork = &state->forks[i];
		}
		philo[i].id = i + 1;
		philo[i].last_eat = 0;
		pthread_mutex_init(&philo[i].philo_eat, NULL);
		i++;
	}
}
