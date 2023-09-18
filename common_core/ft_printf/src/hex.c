/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_width(uintptr_t ptr)
{
	int				siz;
	uintptr_t		tmp;

	siz = 0;
	tmp = ptr;
	while (true)
	{
		tmp /= 16;
		siz++;
		if (tmp == 0)
			break ;
	}
	return (siz);
}

void	ft_puthex_min_width(int *total, t_params params, int width)
{
	if (params.min_width > width && params.flags & ZERO_PAD)
	{
		if (width < params.precision)
			ft_print_min_width(total, params, true, params.precision);
		else
			ft_print_min_width(total, params, true, width);
	}
}

void	ft_puthex_num(int *total, t_params params, uintptr_t hex)
{
	char	str[16];
	int		idx;
	int		width;

	if (params.precision == 0 && hex == 0)
		return ;
	width = ft_hex_width(hex);
	if (params.flags & HEX_PREFIX)
		width += 2;
	ft_puthex_min_width(total, params, width);
	while (width < params.precision && width++)
		ft_putchar_count(total, '0');
	idx = 0;
	while (true)
	{
		if (params.flags & BIG_HEX)
			str[idx++] = "0123456789ABCDEF"[hex % 16];
		else
			str[idx++] = "0123456789abcdef"[hex % 16];
		hex /= 16;
		if (hex == 0)
			break ;
	}
	while (idx-- > 0)
		ft_putchar_count(total, str[idx]);
}

void	ft_puthex(int *total, t_params params, uintptr_t hex)
{
	int		width;

	width = ft_hex_width(hex);
	if (params.precision > width)
		width = params.precision;
	if (params.precision == 0 && hex == 0)
		width--;
	if (params.flags & HEX_PREFIX && hex != 0
		&& !(params.precision == 0 && hex == 0))
		width += 2;
	if (params.min_width > width && (params.flags & ZERO_PAD) == 0)
		ft_print_min_width(total, params, true, width);
	if (hex > 0 && params.flags & HEX_PREFIX && params.flags & BIG_HEX)
		ft_putstr_count(total, "0X");
	if (hex > 0 && params.flags & HEX_PREFIX && (params.flags & BIG_HEX) == 0)
		ft_putstr_count(total, "0x");
	ft_puthex_num(total, params, hex);
	ft_print_min_width(total, params, false, width);
}

void	ft_putptr(int *total, t_params params, void *ptr)
{
	uintptr_t	uptr;

	if (ptr == NULL)
	{
		params.flags &= ~ZERO_PAD;
		ft_print_min_width(total, params, true, 5);
		ft_putstr_count(total, "(nil)");
		ft_print_min_width(total, params, false, 5);
		return ;
	}
	uptr = (uintptr_t) ptr;
	params.flags |= HEX_PREFIX;
	ft_puthex(total, params, uptr);
}
