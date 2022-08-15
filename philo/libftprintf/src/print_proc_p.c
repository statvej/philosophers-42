/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_proc_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statvej <statvej@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:07:27 by fstaryk           #+#    #+#             */
/*   Updated: 2022/05/26 13:04:44 by statvej          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libftprintf.h"

static int	ft_hex_len(unsigned long n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		count++;
		n = n / 16;
	}
	return (count);
}

static int	ft_put_addr(unsigned long num, char *base)
{
	int	ret;

	ret = 0;
	if (num == 0)
		return (lputchar('0'));
	if (num >= 16)
	{
		ret += ft_put_addr(num / 16, base);
		ret += lputchar(base[num % 16]);
	}
	else
		ret += lputchar(base[num % 16]);
	return (ret);
}

int	ft_print_p(t_flags flags, va_list args)
{
	unsigned long int	prntbl;
	int					ret;
	int					num_len;
	int					space_count;
	int					char_fill;

	prntbl = va_arg(args, unsigned long int);
	num_len = ft_hex_len(prntbl);
	ret = 0;
	space_count = flags.min_chars - num_len - 2;
	char_fill = ' ';
	if (!flags.left_just)
		ret += lputnchar(char_fill, space_count);
	if (prntbl == ULONG_MAX)
		ret += lputstr("0xffffffffffffffff");
	else
	{
		ret += lputstr("0x");
		ret += lputnbrbase(prntbl, HEX_SMALL);
	}
	if (flags.left_just)
		ret += lputnchar(char_fill, space_count);
	return (ret);
}
