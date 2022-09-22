/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:40:26 by fstaryk           #+#    #+#             */
/*   Updated: 2022/09/22 13:52:18 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// void ft_putstr(char *str){
// 	while (*str)
// 		write(1, str++, 1);	
// }

// void	ft_putnbr(int nb)
// {
// 	if (nb < 0 && nb / 10 == 0)
// 	{
// 		ft_putchar('-');
// 	}
// 	if (nb / 10 != 0)
// 	{
// 		ft_putnbr(nb / 10);
// 	}
// 	if (nb % 10 < 0)
// 	{
// 		ft_putchar((nb % 10) * -1 + '0');
// 	}
// 	else
// 	{
// 		ft_putchar(nb % 10 + '0');
// 	}
// }

void	print_output(t_philo *philo, char *msg){
	sem_wait(philo->gdata->output);
	printf("time no eat %llu\t", get_cur_time() - philo->last_eat);
	if((int)get_cur_time() - (int)philo->last_eat > philo->gdata->time_to_die &&
					!philo->gdata->dead)
	{
		// printf("it thinks its dead\n");
		philo->gdata->dead = 1;
		printf("%llu %d %s\n",\
			get_cur_time() - philo->gdata->start_time, philo->ind, "died");
		exit(1);
	}
	if(!philo->gdata->dead)
		printf("%llu %d %s\n",\
			get_cur_time() - philo->gdata->start_time, philo->ind, msg);
	sem_post(philo->gdata->output);
}

// void	print_output(t_philo *philo, char *msg){
// 	if(get_cur_time() - philo->last_eat >= philo->gdata->time_to_die &&
// 					!philo->gdata->dead)
// 	{
// 		philo->gdata->dead = 1;
// 		ft_putnbr((int)(get_cur_time() - philo->gdata->start_time));
// 		ft_putchar(' ');
// 		ft_putnbr(philo->ind);
// 		ft_putstr(" is dead\n");
// 		return ;
// 	}
// 	if(!philo->gdata->dead)
// 	{
// 		ft_putnbr((int)(get_cur_time() - philo->gdata->start_time));
// 		ft_putchar(' ');
// 		ft_putnbr(philo->ind);
// 		ft_putchar(' ');
// 		ft_putstr(msg);
// 		ft_putchar('\n');
// 	}	
// }