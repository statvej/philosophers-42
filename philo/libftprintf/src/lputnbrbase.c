/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lputnbrbase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statvej <statvej@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:12:33 by fstaryk           #+#    #+#             */
/*   Updated: 2022/05/25 15:45:14 by statvej          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libftprintf.h"

static int	ft_putnbr_base_rec(unsigned long long int nbr, char *base, int size)
{
	unsigned char			a;
	unsigned long long int	n;
	int						ret;

	ret = 0;
	n = nbr;
	if (n >= (unsigned int)size)
		ret += ft_putnbr_base_rec(n / size, base, size);
	a = base[n % size];
	write(1, &a, 1);
	ret++;
	return (ret);
}

static int	ft_ver_bas(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == base[i + 1])
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

int	lputnbrbase(unsigned long long int nbr, char *base)
{
	int	s;
	int	ret;

	ret = 0;
	s = 0;
	if (ft_ver_bas(base) == 1)
	{
		while (base[s] != '\0')
			s++;
		ret = ft_putnbr_base_rec(nbr, base, s);
	}
	return (ret);
}

// int main(){
//     return (lputnbrbase(100, HEX_SMALL));
// }
