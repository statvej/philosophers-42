/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statvej <statvej@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:39:14 by fstaryk           #+#    #+#             */
/*   Updated: 2022/05/26 13:13:04 by statvej          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libftprintf.h"

char	*ft_str_chr_str(char *str, char *find)
{
	char	*temp;

	while (*str)
	{
		temp = find;
		while (*temp)
		{
			if (*str == *temp)
				return (str);
			temp++;
		}
		str++;
	}
	return (NULL);
}

int	get_int_len(int n)
{
	int	comper;
	int	count;

	comper = 1;
	count = 0;
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n *= -1;
	if (n == 0)
		return (1);
	while (n / comper >= 1)
	{
		comper *= 10;
		count++;
	}
	return (count);
}

int	get_space_count(t_flags flags, int num_len, int n)
{
	int	ret;

	if (num_len >= flags.precision)
		ret = flags.min_chars - num_len;
	else if (num_len < flags.precision)
		ret = flags.min_chars - flags.precision;
	else if (ret <= 0)
		return (0);
	if (flags.sign || n < 0)
		ret--;
	return (ret);
}

int	get_char_fill(t_flags flags)
{
	if (flags.zero)
		return ('0');
	else
		return (' ');
}

int	get_space_count_str(t_flags flags, char *str)
{
	int	len;
	int	ret;

	len = ft_strlen(str);
	if (len >= flags.precision)
		ret = flags.min_chars - len;
	else if (len < flags.precision)
		ret = flags.min_chars - flags.precision;
	else if (ret <= 0)
		return (0);
	return (ret);
}

// int main(){
//     return (get_int_len(1342));
// }
