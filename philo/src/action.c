/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:35:31 by fstaryk           #+#    #+#             */
/*   Updated: 2022/09/19 15:00:09 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void *action(void* arg){
		t_philo	*philo;
		t_gdata	*data;

		philo = (t_philo *)arg;
		data = philo->gdata;
		printf("CHECK!!!\n");
		if(data->num_of_philo == 1)
		{
			ft_sleep(data->time_to_die);
			printf("CHECK PRINT!!!\n");
			print_output(philo, "died");
			return NULL;
		}
		return NULL;
}
