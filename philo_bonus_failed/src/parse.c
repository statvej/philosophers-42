/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:41:33 by fstaryk           #+#    #+#             */
/*   Updated: 2022/09/22 14:02:24 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void create_sem(t_gdata *gdata){
	sem_unlink("forks");
	sem_unlink("output");
	gdata->forks = sem_open("forks", O_CREAT, S_IRWXU, gdata->num_of_philo);
	gdata->output = sem_open("output", O_CREAT, S_IRWXU, 1);
}

void init_philo(int num, t_gdata *gdata){
	// gdata->start_time = get_cur_time(); 
	gdata->dead = 0;
	while (num > 0)
	{
		// gdata->philos[num].last_eat = get_cur_time();
		gdata->philos[num].ind = num;
		gdata->philos[num].meal_count = 0;
		gdata->philos[num].gdata = gdata;
		num--;
	}
}

int	init_forks(int n, t_gdata *data)
{
	data->start_time = get_cur_time();
	while (n > 0)
	{
		data->philos[n].pid = fork();
		if (data->philos[n].pid == 0)
			action(&(data->philos[n]));
		n--;
	}
	return (1);
}
// void init_forks(int num, t_gdata *data){
// 	while (num > 0)
// 	{
// 		// data->philos[num].pid = fork();
// 		if(data->philos[num].pid == 0){
// 			fprintf(stderr, "creating of a child\n");
// 			action(&data->philos[num]);
// 		}
// 		num--;
// 	}	
// 	printf("my processes are %d ,%d", data->philos[1].pid, data->philos[2].pid);
// }

t_gdata *get_global_data(int ac, char ** av){
	t_gdata *gdata;
	
	if(ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) <= 0 || ft_atoi(av[3]) <= 0
							|| ft_atoi(av[4]) <= 0)
		return (NULL);
	gdata = (t_gdata *)malloc(sizeof(t_gdata));
	gdata->num_of_philo = ft_atoi(av[1]);
	gdata->time_to_die = ft_atoi(av[2]);
	gdata->time_to_eat = ft_atoi(av[3]);
	gdata->time_to_sleep = ft_atoi(av[4]);
	if(ac == 6)
	{
		gdata->max_times_eat = ft_atoi(av[5]);
		if(ft_atoi(av[5]) <= 0)
			return (NULL);
	}
	else
		gdata->max_times_eat = -1;
	// printf("num o philo is %d\n", gdata->num_of_philo);
	create_sem(gdata);
	init_philo(gdata->num_of_philo, gdata);
	init_forks(gdata->num_of_philo, gdata);
	return gdata;
}
