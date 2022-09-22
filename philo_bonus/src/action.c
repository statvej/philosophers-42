/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:35:31 by fstaryk           #+#    #+#             */
/*   Updated: 2022/09/22 17:10:28 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void action(t_philo *philo){
		t_gdata	*data;

		data = philo->gdata;
		// if(philo->ind == 1)
		// 	data->all_philos_ready = 1;
		// while (!data->all_philos_ready)
		// 	usleep(1);
		if(data->num_of_philo == 1)
		{
			ft_sleep(data->time_to_die);
			print_output(philo, "died");
			exit(0);
		}
		if(philo->ind % 2)
			ft_sleep(data->time_to_eat);
		while (!data->dead)
		{
			eat(philo);
			if(philo->meal_count == data->max_times_eat)
				exit(0);
			print_output(philo, "is sleeping");
			ft_sleep(data->time_to_sleep);
			print_output(philo, "is thinking");
		}
		exit(0);
}
