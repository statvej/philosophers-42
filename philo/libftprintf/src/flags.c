/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statvej <statvej@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:56:18 by fstaryk           #+#    #+#             */
/*   Updated: 2022/05/26 13:02:32 by statvej          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libftprintf.h"

t_flags	init_flags(void)
{
	t_flags	ret;

	ret.left_just = 0;
	ret.min_chars = 0;
	ret.precision = -1;
	ret.sign = 0;
	ret.slash = 0;
	ret.space = 0;
	ret.zero = 0;
	return (ret);
}

static int	get_flags_sub(t_flags *flags, int i, char *str)
{
	if (str[i] == '-')
		flags->left_just = 1;
	else if (str[i] == '+')
		flags->sign = 1;
	else if (str[i] == '#')
		flags->slash = 1;
	else if (str[i] == ' ')
		flags->space = 1;
	else if (ft_isdigit(str[i]) && str[i] != '0')
	{
		flags->min_chars = ft_atoi(&str[i]);
		i += get_int_len(flags->min_chars) - 1;
	}
	else if (str[i] == '.')
	{
		flags->precision = ft_atoi(&str[i + 1]);
		i += get_int_len(flags->precision);
	}
	else if (str[i] == '0')
		flags->zero = 1;
	i++;
	return (i);
}

t_flags	get_flags(char *str, int len)
{
	t_flags	flags;
	int		i;

	flags = init_flags();
	i = 0;
	while (i < len && str[i])
		i = get_flags_sub(&flags, i, str);
	return (flags);
}
