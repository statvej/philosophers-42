/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:57:22 by fstaryk           #+#    #+#             */
/*   Updated: 2022/09/21 16:35:39 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	eat(t_philo *philo){
	t_gdata *data;

	data = philo->gdata;
	sem_wait(data->forks);
	print_output(philo, "has taken a fork");
	sem_wait(data->forks);
	print_output(philo, "has taken a fork");
	print_output(philo, "is eating");
	ft_sleep(data->time_to_eat);
	philo->last_eat = get_cur_time();
	philo->meal_count += 1;
	sem_post(data->forks);
	sem_post(data->forks);
}
