/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:40:26 by fstaryk           #+#    #+#             */
/*   Updated: 2022/09/19 14:48:00 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_output(t_philo *philo, char *msg){
	pthread_mutex_lock(&philo->gdata->output);
	printf("%d %llu %s\n", philo->ind,
		get_cur_time() - philo->gdata->start_time, msg);
	pthread_mutex_unlock(&philo->gdata->output);
}