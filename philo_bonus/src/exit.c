/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:05:41 by fstaryk           #+#    #+#             */
/*   Updated: 2022/09/23 17:31:39 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"


void    finish_action(int i, t_gdata *data){
    // int sig;

    // waitpid(-1, &sig, 0);
    // if(sig != 0)
    // {
        printf("\ttryiung to kill the kids\n");
        while (i >= 0)
        {
            kill(data->philos[i--].pid, 42);
        }
    // }
}

void    destroy(t_gdata *data)
{
    sem_unlink("death");
    sem_unlink("forks");
    sem_unlink("output");
    sem_close(data->death);
    sem_close(data->forks);
    sem_close(data->output);
}

void    destructor(t_gdata *data){
    finish_action(data->num_of_philo, data);
    destroy(data);
    free(data);
}
