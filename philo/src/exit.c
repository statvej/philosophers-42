/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:05:41 by fstaryk           #+#    #+#             */
/*   Updated: 2022/09/19 15:51:07 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"


void    finish_action(int i, t_gdata *data){
    while (i)
        pthread_join(data->philos[i--].thread, NULL);
}

void    destroy(int n, t_gdata *data)
{
    int i = 0;

    i = 0;
    while (i <= n)
    {
        pthread_detach(data->philos[i].thread);
        pthread_mutex_destroy(&data->forks[i]);
        i++;
    }
    pthread_mutex_destroy(&data->eating);
    pthread_mutex_destroy(&data->output);
}

void    destructor(t_gdata *data){
    finish_action(data->num_of_philo, data);
    destroy(data->num_of_philo, data);
    free(data);
}
