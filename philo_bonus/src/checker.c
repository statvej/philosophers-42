/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:38:54 by fstaryk           #+#    #+#             */
/*   Updated: 2022/09/23 15:37:28 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	checker(t_gdata *data)
{
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
					printf("number is %d, time to die %d, time no eat %llu\n", i, data->time_to_die, t - data->philos[i].last_eat);
					sem_post(data->death);
					print_output(&data->philos[i], "died");
				}
			}
			i--;
		}
			
	}
		
}
