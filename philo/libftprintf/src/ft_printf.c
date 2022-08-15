/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statvej <statvej@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:42:57 by fstaryk           #+#    #+#             */
/*   Updated: 2022/05/26 13:15:05 by statvej          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		prnt_count;

	prnt_count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			prnt_count += handle_printing((char **)&str, args);
		else
			prnt_count += lputchar(*str);
		str++;
	}
	va_end(args);
	return (prnt_count);
}

// int	main(void)
// {
// 	//char *pp = malloc(23456);
// 	fprintf(stderr, " |%p| |%p| ", (void *)-1, ULONG_MAX);
// 	ft_printf(" |%p| |%p| ", (void *)-1, ULONG_MAX);
// 	return (0);
// }
