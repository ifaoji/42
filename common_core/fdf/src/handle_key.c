/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	handle_move(int keycode, t_data *param)
{
	if (keycode == XK_a)
		param->view.move_x -= 5;
	else if (keycode == XK_d)
		param->view.move_x += 5;
	else if (keycode == XK_w)
		param->view.move_y -= 5;
	else if (keycode == XK_s)
		param->view.move_y += 5;
	else if (keycode == XK_minus)
		param->view.move_z = ft_maxf(param->view.move_z - 0.1, 0);
	else if (keycode == XK_equal)
		param->view.move_z = ft_minf(param->view.move_z + 0.1, 10);
}

static void	handle_rotate(int keycode, t_data *param)
{
	if (param->view.parralel_projection)
		return ;
	if (keycode == XK_Up)
		param->view.rotate_x = (param->view.rotate_x + 1) % 360;
	else if (keycode == XK_Down)
	{
		param->view.rotate_x = param->view.rotate_x - 1;
		if (param->view.rotate_x < 0)
			param->view.rotate_x = 359;
	}
	else if (keycode == XK_Right)
		param->view.rotate_y = (param->view.rotate_y + 1) % 360;
	else if (keycode == XK_Left)
	{
		param->view.rotate_y = param->view.rotate_y - 1;
		if (param->view.rotate_y < 0)
			param->view.rotate_y = 359;
	}
}

int	handle_key(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		ft_close(data, 0);
	else
	{
		handle_move(keycode, data);
		handle_rotate(keycode, data);
		if (keycode == XK_space)
			data->view.parralel_projection = !data->view.parralel_projection;
		else if (keycode == XK_h)
			data->view.render_text = !data->view.render_text;
	}
	ft_render(data);
	return (0);
}
