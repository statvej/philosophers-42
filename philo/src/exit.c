/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:05:41 by fstaryk           #+#    #+#             */
/*   Updated: 2022/09/23 18:55:01 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"


void    finish_action(int i, t_gdata *data){
    while (i)
        pthread_join(data->philos[i--].thread, NULL);
    pthread_join(data->checker, NULL);
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
    pthread_detach(data->checker);
    pthread_mutex_destroy(&data->m_death);
    pthread_mutex_destroy(&data->output);
}

void    destructor(t_gdata *data){
    finish_action(data->num_of_philo, data);
    destroy(data->num_of_philo, data);
    free(data);
}
