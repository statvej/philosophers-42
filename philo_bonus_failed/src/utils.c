/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:11:54 by fstaryk           #+#    #+#             */
/*   Updated: 2022/09/21 19:28:12 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

unsigned long long	get_cur_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void ft_sleep(int ms){
	unsigned long long	i;

	i = get_cur_time();
	while(1)
		if((int)(get_cur_time() - i) >= ms)
			break ;
}

// int	diff(unsigned long long pre, unsigned long long post)
// {
// 	return (pre - post);
// }
