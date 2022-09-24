/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:35:31 by fstaryk           #+#    #+#             */
/*   Updated: 2022/09/24 18:38:09 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void *action(void* arg){
		t_philo	*philo;
		t_gdata	*data;

		philo = (t_philo *)arg;
		data = philo->gdata;
		if(philo->ind == 1)
		{
			data->all_philos_ready = 1;
			data->start_time = get_cur_time();
		}
		while (!data->all_philos_ready)
			usleep(1);
		if(data->num_of_philo == 1)
		{
			ft_sleep(data->time_to_die);
			print_output(philo, "died");
			return NULL;
		}
		if(philo->ind % 2)
			usleep(data->time_to_eat * 1000);
		while (!data->dead)
		{
			eat(philo);
			if(philo->meal_count == data->max_times_eat)
				return (NULL);
			print_output(philo, "is sleeping");
			ft_sleep(data->time_to_sleep);
			print_output(philo, "is thinking");
		}
		return NULL;
}
