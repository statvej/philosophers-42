/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:54:24 by fstaryk           #+#    #+#             */
/*   Updated: 2022/09/23 17:57:09 by fstaryk          ###   ########.fr       */
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
				if(data->time_to_die > (int)(t - data->philos[i].last_eat))
				{
					printf("number is %d, time to die %d, time no eat %llu\n", i, data->time_to_die, t - data->philos[i].last_eat);
                    // sem_post(data->death);
					print_output(&data->philos[i], "died");
				}
			}
			i--;
		}
	}
}
