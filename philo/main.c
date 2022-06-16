/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:33:39 by msosnova          #+#    #+#             */
/*   Updated: 2021/12/28 18:33:53 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_state	state;
	t_philo	*philo;

	if (argc != 5 && argc != 6)
	{
		ft_putstr("Wrong number of arguments\n");
		return (0);
	}
	if (ft_init_data(argc, argv, &state) == 0)
		return (0);
	philo = malloc(state.n_philo * sizeof(t_philo));
	if (!philo)
	{
		ft_putstr("Fatal error\n");
		return (0);
	}
	ft_init_philo(&state, philo);
	ft_start_thread(&state, philo);
	ft_destroy_mutex(&state, philo);
	free(state.forks);
	free(philo);
	return (1);
}
