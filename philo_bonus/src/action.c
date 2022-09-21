/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:35:31 by fstaryk           #+#    #+#             */
/*   Updated: 2022/09/21 20:28:41 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void *action(t_philo *philo){
		t_gdata	*data;

		data = philo->gdata;
		// fprintf(stderr, "start of action\n");
		if(data->num_of_philo == 1)
		{
			ft_sleep(data->time_to_die);
			print_output(philo, "died");
			exit(0);
		}
		while (!data->dead)
		{
			// fprintf(stderr, "IT GOES TO ACTION LOOOP\n");
			eat(philo);
			if(philo->meal_count == data->max_times_eat)
				break ;
			print_output(philo, "is sleeping");
			ft_sleep(data->time_to_sleep);
			print_output(philo, "is thinking");
		}
		exit(0);
}
