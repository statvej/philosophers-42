/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:40:26 by fstaryk           #+#    #+#             */
/*   Updated: 2022/09/24 16:12:06 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void check_if_anybody_died(t_gdata *data){
	int					i;
	unsigned long long	t;

	while (1)
	{
		i = data->num_of_philo;
		while (i > 0)
		{
			if(data->philos[i].ind)
			{
				t = get_cur_time();
				if(data->time_to_die > (int)(t - data->philos[i].last_eat))
				{
					data->dead = 1;
					printf("%llu %d %s\n",data->philos[i].last_eat - data->start_time\
								 + data->time_to_die, data->philos[i].ind, "died");
					exit(1);
				}
			}
			i--;
		}
	}
}

void	print_output(t_philo *philo, char *msg){
	sem_wait(philo->gdata->output);
		// printf("time no eat %d\t", get_cur_time() - philo->last_eat);
	// if((int)(get_cur_time() - philo->last_eat) >= philo->gdata->time_to_die &&
	// 				!philo->gdata->dead)
	// {
	// 	philo->gdata->dead = 1;
	// 	printf("%llu %d %s\n",philo->last_eat - philo->gdata->start_time\
	// 						 + philo->gdata->time_to_die, philo->ind, "died");
	// 	// sem_post(philo->gdata->output);
	// 	sem_post(philo->gdata->death);
	// 	exit(1);
	// }
	check_if_anybody_died(philo->gdata);
	if(!philo->gdata->dead)
		printf("%llu %d %s\n",\
			get_cur_time() - philo->gdata->start_time, philo->ind, msg);
	sem_post(philo->gdata->output);
}
