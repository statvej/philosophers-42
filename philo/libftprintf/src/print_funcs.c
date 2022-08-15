/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statvej <statvej@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:22:32 by fstaryk           #+#    #+#             */
/*   Updated: 2022/05/26 13:16:35 by statvej          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libftprintf.h"

int	lputstr(char *s)
{
	int	len;

	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}

int	lputchar(char c)
{
	write(1, (const char *)&c, 1);
	return (1);
}

int	lputnchar(int c, int n)
{
	int	i;

	i = 0;
	while (n-- > 0)
		i += lputchar(c);
	return (i);
}

int	lputnstr(char *str, int n)
{
	if (n >= ft_strlen(str))
		n = ft_strlen(str);
	write(1, str, n);
	return (n);
}
// int main(){
// 	lputnchar('a', 5);
// }
