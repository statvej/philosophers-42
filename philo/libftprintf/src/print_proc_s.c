/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_proc_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statvej <statvej@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:03:37 by fstaryk           #+#    #+#             */
/*   Updated: 2022/05/25 15:45:33 by statvej          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libftprintf.h"

int	ft_print_s(const t_flags flags, va_list args)
{
	char	*str;
	int		ret;
	int		space_count;

	str = va_arg(args, char *);
	if (!str)
		return (lputstr("(null)"));
	ret = 0;
	space_count = get_space_count_str(flags, str);
	if (flags.precision == 0)
	{
		return (ret);
	}
	if (!flags.left_just)
		ret += lputnchar(' ', space_count);
	if (flags.precision == -1)
		ret += lputstr(str);
	else
		ret += lputnstr(str, flags.precision);
	if (flags.left_just)
		ret += lputnchar(' ', space_count);
	return (ret);
}
