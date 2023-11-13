/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_to_sub(int a, int b)
{
	if (a < b)
		return (1);
	else
		return (-1);
}

static int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

static void	ft_draw_line_i(void *img, t_point a, t_point b, uint32_t color)
{
	struct s_dl	d;

	d.dx = ft_abs(b.x - a.x);
	d.dy = ft_abs(b.y - a.y);
	d.sx = ft_to_sub(a.x, b.x);
	d.sy = ft_to_sub(a.y, b.y);
	d.err = d.dx - d.dy;
	ft_set_pixel(img, a.x, a.y, color);
	while (a.x != b.x || a.y != b.y)
	{
		ft_set_pixel(img, a.x, a.y, color);
		d.e2 = 2 * d.err;
		if (d.e2 > -d.dy)
		{
			d.err -= d.dy;
			a.x += d.sx;
		}
		if (d.e2 < d.dx)
		{
			d.err += d.dx;
			a.y += d.sy;
		}
	}
}

void	ft_draw_line(void *img, t_pointf a, t_pointf b, uint32_t color)
{
	ft_draw_line_i(img, ft_point(a.x, a.y), ft_point(b.x, b.y), color);
}
