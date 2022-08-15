/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_proc_xX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statvej <statvej@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:21:56 by fstaryk           #+#    #+#             */
/*   Updated: 2022/05/26 13:13:21 by statvej          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libftprintf.h"

int	get_int_len_in_hex(unsigned long long int nbr)
{
	long int				comper;
	long int				count;
	unsigned long long int	n;

	comper = 1;
	count = 0;
	n = nbr;
	if (n == 0)
		return (1);
	while (n / comper >= 1)
	{
		comper *= 16;
		count++;
	}
	return (count);
}

int	get_hex_space_count(t_flags flags, int num_len)
{
	int	ret;

	if (num_len >= flags.precision)
		ret = flags.min_chars - num_len;
	else if (num_len < flags.precision)
		ret = flags.min_chars - flags.precision;
	else if (ret <= 0)
		return (0);
	if (flags.slash)
		ret -= 2;
	return (ret);
}

int	ft_print_x(const t_flags flags, va_list args, char *base)
{
	unsigned int	prntbl;
	int				ret;
	int				num_len;
	int				space_count;

	prntbl = va_arg(args, unsigned int);
	ret = 0;
	num_len = get_int_len_in_hex(prntbl);
	space_count = get_hex_space_count(flags, num_len);
	if (!flags.left_just)
		ret += lputnchar(get_char_fill(flags), space_count);
	if (flags.slash && prntbl)
	{
		if (ft_strncmp(base, HEX_SMALL, 16) == 0)
			ret += lputstr("0x");
		else
			ret += lputstr("0X");
	}
	if (flags.precision)
		ret += lputnchar('0', flags.precision - num_len);
	ret += lputnbrbase(prntbl, base);
	if (flags.left_just)
		ret += lputnchar(get_char_fill(flags), space_count);
	return (ret);
}

// int main()
// {
//     return (get_int_len_in_hex(-100));
// }