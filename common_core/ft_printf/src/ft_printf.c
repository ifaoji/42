/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_min_width(int *total, t_params params, bool left, int amount)
{
	char	placeholder;

	if ((left && params.flags & JUSTIFY_LEFT)
		|| (!left && (params.flags & JUSTIFY_LEFT) == 0))
		return ;
	if (params.flags & ZERO_PAD && params.precision < 0 && left
		&& params.type != STRING)
		placeholder = '0';
	else
		placeholder = ' ';
	while (params.min_width > amount++)
		ft_putchar_count(total, placeholder);
}

void	ft_print_params(int *total, t_params params)
{
	if (params.type == CHARACTER)
		return (ft_putchar(total, params, va_arg(*params.args, int)));
	if (params.type == STRING)
		return (ft_putstr(total, params, va_arg(*params.args, char *)));
	if (params.type == POINTER)
		return (ft_putptr(total, params, va_arg(*params.args, char *)));
	if (params.type == HEXADECIMAL)
		return (ft_puthex(total, params, va_arg(*params.args, unsigned int)));
	if (params.type == INTEGER)
		return (ft_putint(total, params, va_arg(*params.args, int)));
	if (params.type == UNSIGNED_INTEGER)
		return (ft_putuint(total, params, va_arg(*params.args, unsigned int)));
	if (params.type == PERCENT)
		ft_putchar_count(total, '%');
}

size_t	ft_printable_len(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != '%')
		len += 1;
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	size_t		next_len;
	t_params	params;
	int			total;

	if (str == NULL)
		return (-1);
	va_start(args, str);
	total = 0;
	while (*str)
	{
		if (*str == '%')
		{
			params = ft_parse_params(str, &args);
			ft_print_params(&total, params);
			str += params.len;
			continue ;
		}
		next_len = ft_printable_len(str);
		write(STDOUT_FILENO, str, next_len);
		total += next_len;
		str += next_len;
	}
	va_end(args);
	return (total);
}
