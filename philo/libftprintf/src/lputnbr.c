/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lputnbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statvej <statvej@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:16:12 by statvej           #+#    #+#             */
/*   Updated: 2022/05/26 13:16:39 by statvej          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libftprintf.h"

static int	sub_print(int nb)
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

int	lputnbr(int nb)
{
	int	ret;

	ret = 0;
	if (nb == 0)
	{
		ret = lputchar('0');
	}
	else if (nb == -2147483648)
	{
		ret = lputstr("2147483648");
	}
	else if (nb > 0)
	{
		ret = sub_print(nb);
	}
	else if (nb < 0)
	{
		nb = nb * (-1);
		ret += sub_print(nb);
	}
	return (ret);
}
