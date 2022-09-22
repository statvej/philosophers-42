/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:05:41 by fstaryk           #+#    #+#             */
/*   Updated: 2022/09/22 14:08:39 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	finish_action(int n, t_gdata *data){
	int	sig;
	int	i;
	
	i = 0;
	while (i <= n)
	{
		waitpid(-1, &sig, 0);
		if(sig != 0)
		{
			i = 0;
			while (i++ < data->num_of_philo)
				kill(data->philos[i].pid, SIGKILL);
			break;	
		}
		i++;
	}
}

void    destroy(t_gdata *data)
{
	sem_unlink("forks");
	sem_unlink("write");
	sem_close(data->forks);
	sem_close(data->output);
}

void    destructor(t_gdata *data){
	finish_action(data->num_of_philo, data);
	destroy(data);
	free(data);
	exit(0);
}
