/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:41:33 by fstaryk           #+#    #+#             */
/*   Updated: 2022/09/23 15:11:00 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void create_sem(t_gdata *gdata){
	sem_unlink("death");
	sem_unlink("forks");
	sem_unlink("output");
	// sem_unlink("mod");
	gdata->death = sem_open("death", O_CREAT, 777, 1);
	gdata->forks = sem_open("forks", O_CREAT, 777, gdata->num_of_philo);
	gdata->output = sem_open("output", O_CREAT, 777, 1);
	// gdata->mod = sem_open("mod", O_CREAT, 777, 1);
	sem_wait(gdata->death);
}

void init_philo(int num, t_gdata *gdata){
	gdata->start_time = get_cur_time();
	gdata->philos_left = num; 
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

void	start_process(int n, t_gdata *data)
{
	pid_t pid;
	
	while (n >= 0)
	{
		pid = fork();
		if(pid == 0)
		{
			data->philos[n].pid = pid;
			action(&data->philos[n]);
		}
		n--;
	}
	pid = fork();
	if(pid == 0)
	{
		data->checker_pid = pid;
		checker(data);
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
	
	create_sem(gdata);
	init_philo(gdata->num_of_philo, gdata);
	start_process(gdata->num_of_philo, gdata);
	return gdata;
}
