/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_proc_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statvej <statvej@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:53:16 by fstaryk           #+#    #+#             */
/*   Updated: 2022/05/26 12:50:14 by statvej          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libftprintf.h"
//in refactoring add print d sub and add left just statements there
static int	ft_print_d_sub(t_flags flags, int ret, int prntbl, int nl)
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
	ret += lputnbr(prntbl);
	return (ret);
}

int	ft_print_d(const t_flags flags, va_list args)
{
	int	prntbl;
	int	num_len;
	int	space_count;
	int	char_fill;
	int	ret;

	prntbl = va_arg(args, int);
	num_len = get_int_len(prntbl);
	space_count = get_space_count(flags, num_len, prntbl);
	char_fill = get_char_fill(flags);
	ret = 0;
	if (!flags.left_just && !flags.zero)
			ret += lputnchar(char_fill, space_count);
	ret += ft_print_d_sub(flags, ret, prntbl, num_len);
	if (flags.left_just && !flags.zero)
		ret += lputnchar(char_fill, space_count);
	return (ret);
}
