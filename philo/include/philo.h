/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:46:19 by msosnova          #+#    #+#             */
/*   Updated: 2022/01/12 16:39:26 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdio.h>

typedef uint64_t		t_time;
typedef pthread_mutex_t	t_mutex;

typedef struct s_state
{
	unsigned int	n_philo;
	unsigned int	n_philo_active;
	t_time			time_eat;
	t_time			time_death;
	t_time			time_sleep;
	unsigned int	n_must_eat;
	t_mutex			ready_msg;
	t_mutex			mutex_finish;
	t_mutex			smn_eat;
	t_mutex			*forks;
	t_time			start_time;
	int				finish;
}					t_state;

typedef struct s_philo
{
	t_state		*state;
	t_mutex		*left_fork;
	t_mutex		*right_fork;
	int			id;
	t_time		last_eat;
	t_mutex		philo_eat;
	pthread_t	thread_id;
	pthread_t	thread_id_timer;
}				t_philo;

void	ft_putstr(char *s);
void	ft_putnbr(uint64_t n);
int		ft_atoi(const char *str);
int		ft_init_data(int argc, char *argv[], t_state *state);
void	ft_destroy_mutex(t_state *state, t_philo *philo);
void	ft_init_philo(t_state *state, t_philo *philo);
void	ft_start_thread(t_state *state, t_philo *philo);
t_time	ft_time(void);
void	ft_message(t_philo *philo, char *s);
void	ft_message_d(t_philo *philo, char *s);
void	*ft_life_philo(void *param);
void	*ft_timer_death(void *param);
void	ft_msleep(t_philo *philo, t_time time);
void	ft_set_finish(t_philo *philo);
int		ft_get_finish(t_philo *philo);

#endif
