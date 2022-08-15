/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_proc_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statvej <statvej@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:29:34 by fstaryk           #+#    #+#             */
/*   Updated: 2022/05/26 12:45:42 by statvej          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libftprintf.h"
//in refactoring add print d sub and add left just statements there

static int	ft_print_u_sub(t_flags flags, int ret, unsigned int prntbl, int nl)
{
	if (flags.sign && prntbl >= 0)
			ret += lputchar('+');
	else if (prntbl < 0)
		ret += lputchar('-');
	else if (flags.space)
		ret += lputchar(' ');
	if (flags.zero)
		ret += lputnchar('0', flags.min_chars - (ret + nl));
	ret += lputnchar('0', flags.precision - nl);
	ret += lput_uint(prntbl);
	return (ret);
}

int	ft_print_u(const t_flags flags, va_list args)
{
	unsigned int	prntbl;
	int				num_len;
	int				space_count;
	int				char_fill;
	int				ret;

	prntbl = va_arg(args, unsigned int);
	num_len = get_uint_len(prntbl);
	space_count = get_uint_space_count(flags, num_len, prntbl);
	char_fill = get_char_fill(flags);
	ret = 0;
	if (!flags.left_just && !flags.zero)
			ret += lputnchar(char_fill, space_count);
	ret += ft_print_u_sub(flags, ret, prntbl, num_len);
	if (flags.left_just && !flags.zero)
		ret += lputnchar(char_fill, space_count);
	return (ret);
}
