/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_window_offset(int line_length, int bits_per_pixel, int x, int y)
{
	return (y * line_length + x * (bits_per_pixel / 8));
}

void	ft_set_pixel(t_img *data, float x, float y, int color)
{
	char	*dest;

	if (data->width <= x || data->height <= y || x < 0 || y < 0)
		return ;
	dest = data->addr
		+ ft_window_offset(data->line_length, data->bits_per_pixel, x, y);
	*(unsigned int *) dest = color;
}
