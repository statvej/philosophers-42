/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:40:26 by fstaryk           #+#    #+#             */
/*   Updated: 2022/09/20 14:51:09 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_output(t_philo *philo, char *msg){
	pthread_mutex_lock(&philo->gdata->output);
		// printf("time no eat %d\t", get_cur_time() - philo->last_eat);
	if(get_cur_time() - philo->last_eat >= philo->gdata->time_to_die &&
					!philo->gdata->dead)
	{
		philo->gdata->dead = 1;
		printf("%d %d %s\n",\
			get_cur_time() - philo->gdata->start_time, philo->ind, "is dead");
		pthread_mutex_unlock(&philo->gdata->output);
		return ;
	}
	if(!philo->gdata->dead)
		printf("%d %d %s\n",\
			get_cur_time() - philo->gdata->start_time, philo->ind, msg);
	pthread_mutex_unlock(&philo->gdata->output);
}