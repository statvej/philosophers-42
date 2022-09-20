/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:57:22 by fstaryk           #+#    #+#             */
/*   Updated: 2022/09/20 14:54:25 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    eat(t_philo *philo){
    t_gdata *data;

    data = philo->gdata;
    pthread_mutex_lock(&data->forks[philo->left_hand]);
    print_output(philo, "grabed a fork");
    pthread_mutex_lock(&data->forks[philo->right_hand]);
    print_output(philo, "grabed a fork");
    pthread_mutex_lock(&data->eating);
    print_output(philo, "is eating");
    pthread_mutex_unlock(&data->eating);
    philo->last_eat = get_cur_time();
    ft_sleep(data->time_to_eat);
    philo->meal_count += 1;
    pthread_mutex_unlock(&data->forks[philo->left_hand]);
    pthread_mutex_unlock(&data->forks[philo->right_hand]);
}
