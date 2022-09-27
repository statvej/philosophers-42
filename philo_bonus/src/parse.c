/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:41:33 by fstaryk           #+#    #+#             */
/*   Updated: 2022/09/27 19:16:35 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void create_sem(int num, t_gdata *gdata){
	sem_unlink("forks");
	sem_unlink("output");
	gdata->forks = sem_open("forks", O_CREAT, S_IRWXU, num);
	gdata->output = sem_open("output", O_CREAT, S_IRWXU, 1);
}

void init_philo(int num, t_gdata *gdata){
	gdata->start_time = get_cur_time(); 
	gdata->dead = 0;
	while (num > 0)
	{
		gdata->philos[num].ind = num;
		gdata->philos[num].meal_count = 0;
		gdata->philos[num].gdata = gdata;
		gdata->philos[num].last_eat = get_cur_time();
		num--;
	}
}

void	init_process(int num, t_gdata *data)
{ 
	int	pid;
	
	while (num > 0)
	{
		pid = fork();
		if(pid == 0)
		{
			// printf("ntering tne process %d\n", num);
			data->philos[num].pid = pid;
			action(&data->philos[num]);
		}
		num--;
	}
}

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
	
	create_sem(gdata->num_of_philo, gdata);
	gdata->all_philos_ready = 0;
	init_philo(gdata->num_of_philo, gdata);
	init_process(gdata->num_of_philo, gdata);
	return gdata;
}
