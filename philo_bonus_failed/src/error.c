/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:10:39 by fstaryk           #+#    #+#             */
/*   Updated: 2022/09/21 16:03:26 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void print_usage(void){
    write(STDERR_FILENO, "Usage is $>./philo [num_of_philo] [time_to_die] ", 49);
    write(STDERR_FILENO, "[time_to_eat] [time_to_sleep] [max_times_to_eat]\n", 50);
}
