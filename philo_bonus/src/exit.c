/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:05:41 by fstaryk           #+#    #+#             */
/*   Updated: 2022/09/30 16:39:12 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"


void    finish_action(int n, t_gdata *data){
	int	seg;

	while (n > 0)
	{
		waitpid(-1, &seg, 0);
		if (seg != 0)
		{
			n = 0;
			while (n++ < data->num_of_philo)
				kill(data->philos[n].pid, 42);
			break ;
		}
		n--;
	}
}

void    destroy(t_gdata *data)
{
    sem_unlink("forks");
    sem_unlink("output");
    sem_close(data->forks);
    sem_close(data->output);
}

void    destructor(t_gdata *data){
    destroy(data);
    finish_action(data->num_of_philo, data);
    free(data);
}
