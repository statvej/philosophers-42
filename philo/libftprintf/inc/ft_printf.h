/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statvej <statvej@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:21:34 by fstaryk           #+#    #+#             */
/*   Updated: 2022/05/26 13:18:58 by statvej          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

# define SPECIFIERS "discpxXu%"
# define HEX_SMALL "0123456789abcdef"
# define HEX_CAPITAL "0123456789ABCDEF"

typedef struct s_flags{
	int	min_chars;
	int	precision;
	int	space;
	int	left_just;
	int	slash;
	int	zero;
	int	sign;
}t_flags;

//Main

int		ft_printf(const char *args, ...);

//Handle printing

int		handle_printing(char **p_str_arg, va_list args);

//Printing functions

int		lputstr(char *s);
int		lputchar(char c);
int		lputnbr(int nb);
int		lputnchar(int c, int n);
int		lputnbrbase(unsigned long long int nbr, char *base);
int		lputnstr(char *str, int n);

//Utils

char	*ft_str_chr_str(char *str, char *find);
int		get_int_len(int n);
int		get_int_len_wflags(int n, t_flags flags);
int		get_space_count(t_flags flags, int num_len, int n);
int		get_char_fill(t_flags flags);
int		get_space_count_str(t_flags flags, char *str);
int		get_int_len_in_hex(unsigned long long int nbr);
int		ft_abs(int nbr);

//Flags

t_flags	get_flags(char *str, int len);

//Print proc DI

int		ft_print_d(const t_flags flags, va_list args);

//Print proc S

int		ft_print_s(const t_flags flags, va_list args);

//Print proc C

int		ft_print_c(const t_flags flags, va_list args);

//Print Proc U

int		ft_print_u(const t_flags flags, va_list args);

//Print proc xX

int		ft_print_x(const t_flags flags, va_list args, char *base);

//Print proc P

int		ft_print_p(t_flags flags, va_list args);

//Itoa BASE

char	*ft_itoa_ullint(unsigned long long int nbr, char *base);
char	*ft_itoa_ulong(unsigned long nbr, char *base);

//Uint Utils

int		lput_uint(unsigned int nb);
int		uint_sub_print(unsigned int nb);
int		get_uint_len(unsigned int n);
int		get_uint_space_count(t_flags flags, long long int nl, long long int n);

#endif
