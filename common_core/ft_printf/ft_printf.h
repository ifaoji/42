/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include "libft/libft.h"

enum	e_type
{
	CHARACTER = 2,
	STRING = 4,
	POINTER = 8,
	INTEGER = 16,
	UNSIGNED_INTEGER = 32,
	HEXADECIMAL = 64,
	PERCENT = 128,
};

enum	e_flags
{
	NONE = 1,
	PLUS = 2,
	SPACE = 4,
	HEX_PREFIX = 8,
	JUSTIFY_LEFT = 16,
	ZERO_PAD = 32,
	BIG_HEX = 64,
};

typedef struct s_params
{
	va_list			*args;
	int				len;
	int				min_width;
	int				precision;
	enum e_flags	flags;
	enum e_type		type;
}	t_params;

// ft_printf.c
int			ft_printf(const char *str, ...);
void		ft_print_min_width(int *total, t_params params,
				bool left, int amount);

// hex.c
void		ft_putptr(int *total, t_params params, void *ptr);
void		ft_puthex(int *total, t_params params, uintptr_t hex);

// params.c
t_params	ft_parse_params(const char *str, va_list *args);

// number.c
int			ft_calculate_width(long int num);
void		ft_putint(int *total, t_params params, int num);
void		ft_putuint(int *total, t_params params, unsigned int num);

// string.c
void		ft_putchar(int *total, t_params params, char c);
void		ft_putstr(int *total, t_params params, char *str);
void		ft_putchar_count(int *total, char c);
void		ft_putstr_count(int *total, char *str);

#endif
