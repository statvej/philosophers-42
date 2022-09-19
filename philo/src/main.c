/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:26:15 by fstaryk           #+#    #+#             */
/*   Updated: 2022/09/19 15:51:41 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int main(int ac, char **av)
{
	t_gdata * data;

	if(ac != 5 && ac != 6){
		print_usage();
		exit(0);
	}
    data = get_global_data(ac, av);
	destructor(data);
    //printf("pp\n");
}
