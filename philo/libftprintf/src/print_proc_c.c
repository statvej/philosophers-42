/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_proc_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statvej <statvej@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:13:33 by fstaryk           #+#    #+#             */
/*   Updated: 2022/05/25 15:45:19 by statvej          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libftprintf.h"

int	ft_print_c(const t_flags flags, va_list args)
{
	int		c;
	int		space_count;
	char	char_fill;
	int		ret;

	c = va_arg(args, int);
	space_count = flags.min_chars - 1;
	char_fill = ' ';
	ret = 0;
	if (!flags.left_just)
	{
		ret += lputnchar(char_fill, space_count);
	}
	ret += lputchar(c);
	if (flags.left_just)
	{
		ret += lputnchar(char_fill, space_count);
	}
	return (ret);
}
