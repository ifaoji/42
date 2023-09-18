/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_calculate_width(long int num)
{
	int				siz;
	unsigned int	tmp;

	siz = 0;
	tmp = num;
	if (num < 0)
	{
		tmp = -num;
		siz += 1;
	}
	while (true)
	{
		tmp /= 10;
		siz++;
		if (tmp == 0)
			break ;
	}
	return (siz);
}

void	ft_putnbr(int *total, t_params params, long int num,
					bool prefix_printed)
{
	char			str[20];
	int				idx;
	int				width;

	if (params.precision == 0 && num == 0)
		return ;
	width = ft_calculate_width(num);
	while (width < params.precision && width++)
		ft_putchar_count(total, '0');
	if (prefix_printed)
		width++;
	if (params.min_width > width
		&& params.flags & ZERO_PAD && params.precision < 0)
		ft_print_min_width(total, params, true, width);
	idx = 0;
	while (true)
	{
		str[idx++] = '0' + (num % 10);
		num /= 10;
		if (num == 0)
			break ;
	}
	while (idx-- > 0)
		ft_putchar_count(total, str[idx]);
}

int	ft_putint_width(t_params params, int num)
{
	int	width;

	width = ft_calculate_width(num);
	if (width <= params.precision)
	{
		width = params.precision;
		if (num < 0)
			width++;
	}
	return (width);
}

void	ft_putint(int *total, t_params params, int num)
{
	int				width;
	unsigned int	tmp;

	width = ft_putint_width(params, num);
	if ((params.flags & (PLUS | SPACE) && num >= 0))
		width += 1;
	if (params.flags & SPACE && num >= 0)
		ft_putchar_count(total, ' ');
	if (params.precision == 0 && num == 0)
		width--;
	if (params.min_width > width
		&& ((params.flags & ZERO_PAD) == 0 || params.precision >= 0))
		ft_print_min_width(total, params, true, width);
	tmp = num;
	if (num < 0)
	{
		ft_putchar_count(total, '-');
		tmp = -num;
	}
	else if (params.flags & PLUS)
		ft_putchar_count(total, '+');
	ft_putnbr(total, params, tmp, num < 0 || params.flags & (PLUS | SPACE));
	ft_print_min_width(total, params, false, width);
}

void	ft_putuint(int *total, t_params params, unsigned int num)
{
	int	width;

	width = ft_calculate_width(num);
	if (width < params.precision)
		width = params.precision;
	if (params.precision == 0 && num == 0)
		width--;
	if (params.min_width > width
		&& ((params.flags & ZERO_PAD) == 0 || params.precision >= 0))
		ft_print_min_width(total, params, true, width);
	ft_putnbr(total, params, num, false);
	ft_print_min_width(total, params, false, width);
}
