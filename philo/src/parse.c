/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:41:33 by fstaryk           #+#    #+#             */
/*   Updated: 2022/08/17 16:40:08 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void create_mutex(int num, t_gdata *gdata){
	while (num)
	{
		pthread_mutex_init(&gdata->forks[num], NULL);
		num--;
	}
	pthread_mutex_init(&gdata->eating);
	pthread_mutex_init(&gdata->output);
}

void create_philo(int num, t_gdata *gdata){
	gdata->start_time = get_cur_time();
	gdata->dead = 0;
	gdata->philos[num].ind = num;
	gdata->philos[num].left_hand = num;
	gdata->philos[num].right_hand = 1;
	gdata->philos[num].meal_count = 0;
	gdata->philos[num].gdata = gdata;
	pthread_create(&gdata->philos[num].thread, NULL, &action, &gdata->philos[n]);
	gdata->philos[num].last_eat = get_cur_time();
	n--;
	while (n)
	{
		gdata->philos[num].ind = num;
		gdata->philos[num].left_hand = num;
		gdata->philos[num].right_hand = 1;
		gdata->philos[num].meal_count = 0;
		gdata->philos[num].gdata = gdata;
		pthread_create(&gdata->philos[num].thread, NULL, &action, &gdata->philos[n]);
		gdata->philos[num].last_eat = get_cur_time();
		n--;
	}
}

t_gdata *get_global_data(int ac, char ** av){
	t_gdata *gdata;
	
	gdata = (t_gdata *)malloc(sizeof(t_gdata));
	gdata->num_of_philo = ft_atoi(av[1]);
	gdata->time_to_die = ft_atoi(av[2]);
	gdata->time_to_eat = ft_atoi(av[3]);
	gdata->time_to_sleep = ft_atoi(av[4]);
	if(ac == 6)
		gdata->max_times_eat = ft_atoi(av[5]);
	else
		gdata->max_times_eat = -1;
	create_mutex(gdata->num_of_philo, gdata);




	return gdata;
}
