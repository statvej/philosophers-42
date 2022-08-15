/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statvej <statvej@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:35:35 by statvej           #+#    #+#             */
/*   Updated: 2022/05/26 12:44:11 by statvej          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libftprintf.h"

int	get_uint_space_count(t_flags flags, long long int nl, long long int n)
{
	int	ret;

	ret = 0;
	if (nl >= flags.precision)
		ret = flags.min_chars - nl;
	else if (nl < flags.precision && flags.precision != -1)
		ret = flags.min_chars - flags.precision;
	else if (ret <= 0)
		return (0);
	return (ret);
}

int	get_uint_len(unsigned int n)
{
	long long unsigned int	comper;
	int						count;

	comper = 1;
	count = 0;
	if (n == 0)
		return (1);
	while (n / comper >= 1)
	{
		comper *= 10;
		count++;
	}
	return (count);
}

int	uint_sub_print(unsigned int nb)
{
	int	comper;
	int	fnumber;
	int	ret;

	ret = 0;
	comper = 1000000000;
	while (nb / comper < 1)
	{
		comper = comper / 10;
	}
	while (comper >= 1)
	{
		fnumber = nb / comper + 48;
		ret += lputchar(fnumber);
		nb = nb - (nb / comper * comper);
		comper = comper / 10;
	}
	return (ret);
}

int	lput_uint(unsigned int nb)
{
	int	ret;

	ret = 0;
	if (nb == 0)
	{
		ret = lputchar('0');
	}
	else if (nb > 0)
	{
		ret = uint_sub_print(nb);
	}
	return (ret);
}
