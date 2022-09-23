/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:40:26 by fstaryk           #+#    #+#             */
/*   Updated: 2022/09/23 19:06:54 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_output(t_philo *philo, char *msg){
	pthread_mutex_lock(&philo->gdata->output);
		// printf("time no eat %d\t", get_cur_time() - philo->last_eat);
	// if((int)(get_cur_time() - philo->last_eat) >= philo->gdata->time_to_die &&
	// 				!philo->gdata->dead)
	// {
	// 	philo->gdata->dead = 1;
	// 	printf("%llu %d %s\n",\
	// 		get_cur_time() - philo->gdata->start_time, philo->ind, "died");
	// 	pthread_mutex_unlock(&philo->gdata->output);
	// 	return ;
	// }
	// if(!philo->gdata->dead)
		printf("%llu %d %s\n",\
			get_cur_time() - philo->gdata->start_time, philo->ind, msg);
	pthread_mutex_unlock(&philo->gdata->output);
}
