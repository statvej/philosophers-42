/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:54:24 by fstaryk           #+#    #+#             */
/*   Updated: 2022/09/23 19:15:37 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*checker(void *arg)
{
	int					i;
	unsigned long long	t;
    t_gdata *data;
    
    data = (t_gdata *)arg;
	while (1)
	{
		i = data->num_of_philo;
		while (i > 0)
		{
			if(data->philos[i].ind)
			{
				t = get_cur_time();
				// printf();
				if(data->time_to_die < (int)(t - data->philos[i].last_eat) &&
							data->dead == 0)
				{
					pthread_mutex_lock(&data->output);
					data->dead = 1;
					printf("%llu %d %s\n", t - data->start_time,\
						data->philos[i].ind, "died");
					pthread_mutex_unlock(&data->output);
				}
			}
			i--;
		}
	}
}
