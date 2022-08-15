/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_printing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statvej <statvej@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:07:39 by fstaryk           #+#    #+#             */
/*   Updated: 2022/05/26 13:10:41 by statvej          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libftprintf.h"

int	handle_printing(char **p_str_arg, va_list args)
{
	int		i;
	char	*str_arg;
	t_flags	flags;

	str_arg = *p_str_arg;
	*p_str_arg = ft_str_chr_str(str_arg + 1, SPECIFIERS);
	flags = get_flags(str_arg + 1, (int)(*p_str_arg - str_arg));
	if (**p_str_arg == 'd' || **p_str_arg == 'i')
		i = ft_print_d(flags, args);
	else if (**p_str_arg == 's')
		i = ft_print_s(flags, args);
	else if (**p_str_arg == 'c')
		i = ft_print_c(flags, args);
	else if (**p_str_arg == 'u')
		i = ft_print_u(flags, args);
	else if (**p_str_arg == '%')
		i = lputchar('%');
	else if (**p_str_arg == 'x')
		i = ft_print_x(flags, args, HEX_SMALL);
	else if (**p_str_arg == 'X')
		i = ft_print_x(flags, args, HEX_CAPITAL);
	else if (**p_str_arg == 'p')
		i = ft_print_p(flags, args);
	return (i);
}
