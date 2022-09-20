/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:26:41 by fstaryk           #+#    #+#             */
/*   Updated: 2022/09/20 16:03:41 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo{
	pthread_t			thread;

	int					meal_count;
	unsigned long long	last_eat;
	int					left_hand;
	int					right_hand;
	int					ind;
	
	struct s_gdata				*gdata;
}t_philo;

typedef struct s_gdata
{
	t_philo				philos[300];

	pthread_mutex_t		forks[300];
	pthread_mutex_t 	eating;
	pthread_mutex_t 	output;
	pthread_mutex_t		ready;
	int					dead;
	
	unsigned long long	start_time;
	int					num_of_philo;
	int 				time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					max_times_eat;
	int					all_philos_ready;
}t_gdata;

//Parsing

t_gdata				*get_global_data(int ac, char **av);

//Errors

void				print_usage(void);

//utils

unsigned long long	get_cur_time(void);
int					ft_atoi(const char *s);
void				ft_sleep(int ms);

//action

void				*action(void *arg);

//output

void				print_output(t_philo *philo, char *msg);

//exit

void			    destructor(t_gdata *data);

//Eating
 
void				eat(t_philo *philo);

#endif