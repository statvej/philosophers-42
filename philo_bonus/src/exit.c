/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:05:41 by fstaryk           #+#    #+#             */
/*   Updated: 2022/09/23 15:09:55 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"


void    finish_action(int i, t_gdata *data){
	printf("\ttryiung to kill the kids\n");
	while (i >= 0)
	{
		kill(data->philos[i--].pid, SIGKILL);
	}
	kill(data->checker_pid, SIGKILL);
}

void    destroy(t_gdata *data)
{
	sem_unlink("death");
	sem_unlink("forks");
	sem_unlink("output");
	// sem_unlink("mod");
	sem_close(data->death);
	sem_close(data->forks);
	sem_close(data->output);
	// sem_close(data->mod);
}

void    destructor(t_gdata *data){
	finish_action(data->num_of_philo, data);
	destroy(data);
	free(data);
}
