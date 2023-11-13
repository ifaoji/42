/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_render_text(t_data *data)
{
	int	color;

	if (!data->view.render_text)
		return ;
	color = 0x00FF00;
	mlx_string_put(data->mlx, data->win, 10, 20, color, "FDF - Controls");
	mlx_string_put(data->mlx, data->win, 10, 35, color, "Rotate: Arrow Keys");
	mlx_string_put(data->mlx, data->win, 10, 50, color, "Move: WASD");
	mlx_string_put(data->mlx, data->win, 10, 65, color, "Zoom: Mousewheel");
	mlx_string_put(data->mlx, data->win, 10, 80, color,
		"Height Modifier: Plus / Minus");
	mlx_string_put(data->mlx, data->win, 10, 95, color,
		"Toggle Parallel Projection: Space");
	mlx_string_put(data->mlx, data->win, 10, 110, color, "Toggle Help: H");
	mlx_string_put(data->mlx, data->win, 10, 125, color, "Exit: Escape");
}
