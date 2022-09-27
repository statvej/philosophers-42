/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:40:26 by fstaryk           #+#    #+#             */
/*   Updated: 2022/09/27 19:18:49 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	check_if_anybody_died(t_gdata *data){
	int					i;
	unsigned long long	t;
	
	t = get_cur_time();
	i = data->num_of_philo;
	while (i > 0)
	{
		// printf("checking philo num %d\n", i);
		if(data->philos[i].ind)
		{
			// printf("since last eat is %d time to die is %d\n", (int)(t - data->philos[i].last_eat), data->time_to_die);
			if(data->time_to_die < (int)(t - data->philos[i].last_eat + 2)
				&& !data->dead)
			{
				data->dead = 1;
				printf("%llu %d %s\n",data->philos[i].last_eat - data->start_time\
							 + data->time_to_die, data->philos[i].ind, "died");
				sem_post(data->output);
				exit(1);
			}
		}
		i--;
	}
	return 0;
}


void	print_output(t_philo *philo, char *msg){
	sem_wait(philo->gdata->output);
		// printf("time no eat %d\t", get_cur_time() - philo->last_eat);
	// if((int)(get_cur_time() - philo->last_eat) >= philo->gdata->time_to_die &&
	// 				!philo->gdata->dead)
	// {
	// 	philo->gdata->dead = 1;
	// 	printf("%llu %d %s\n",philo->last_eat - philo->gdata->start_time\
 	// 					 + philo->gdata->time_to_die, philo->ind, "died");
	// 	pthread_mutex_unlock(&philo->gdata->output);
	// 	return ;
	// }
	if(check_if_anybody_died(philo->gdata))
		return ;
	if(!philo->gdata->dead)
		printf("%llu %d %s\n",\
			get_cur_time() - philo->gdata->start_time, philo->ind, msg);
	sem_post(philo->gdata->output);
}
