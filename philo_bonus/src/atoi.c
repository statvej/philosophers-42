/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:28:55 by fstaryk           #+#    #+#             */
/*   Updated: 2022/08/17 15:29:15 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

static bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static bool	ismode(char c)
{
	return (c == '+' || c == '-');
}

static bool	is_delim(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int	ft_atoi(const char *s)
{
	int	res;
	int	count;
	int	mod;
	int	i;

	res = 0;
	count = 0;
	mod = 1;
	i = 0;
	while (is_delim(s[i]))
		i++;
	if (ismode(s[i]))
	{
		if (s[i] == '-')
			mod = -1;
		i++;
	}
	while (is_digit(s[count + i]))
	{
		res = res * 10 + s[count + i] - '0';
		count++;
	}
	return (res * mod);
}
