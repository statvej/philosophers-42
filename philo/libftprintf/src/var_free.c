/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:20:09 by fstaryk           #+#    #+#             */
/*   Updated: 2022/07/15 19:13:27 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libftprintf.h"

void	multi_free(int n, ...)
{
	va_list	args;
	int		i;
	void	*p;

	va_start(args, n);
	i = 0;
	while (i < n)
	{
		p = va_arg(args, void *);
		free(p);
		i++;
	}
	va_end(args);
}

void	free_double_ptr(void **ptr, size_t size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
