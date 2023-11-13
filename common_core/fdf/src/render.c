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

void	ft_fix_points(t_pointf *points, int point_amount)
{
	float	min_x;
	float	min_y;
	float	min_z;
	int		idx;

	min_x = 1e9;
	min_y = 1e9;
	min_z = 1e9;
	idx = -1;
	while (++idx < point_amount)
	{
		if (points[idx].x < min_x)
			min_x = points[idx].x;
		if (points[idx].y < min_y)
			min_y = points[idx].y;
		if (points[idx].z < min_z)
			min_z = points[idx].z;
	}
	idx = -1;
	while (++idx < point_amount)
	{
		points[idx].x -= min_x;
		points[idx].y -= min_y;
		points[idx].z -= min_z;
	}
}

static void	ft_to_3d(t_data *data)
{
	int			idx;

	idx = 0;
	while (idx < data->total_points)
	{
		data->points_view[idx] = data->points[idx];
		data->points_view[idx].z *= data->view.move_z;
		scale(&data->points_view[idx], data->view.scale,
			data->view.scale, data->view.scale);
		if (data->view.parralel_projection)
		{
			rotate_x(&data->points_view[idx], 90);
			rotate_y(&data->points_view[idx], 0);
			rotate_z(&data->points_view[idx], 0);
		}
		else
		{
			rotate_x(&data->points_view[idx], data->view.rotate_x);
			rotate_y(&data->points_view[idx], data->view.rotate_y);
			rotate_z(&data->points_view[idx], data->view.rotate_z);
		}
		data->points_view[idx].x += (float) data->width / 2;
		data->points_view[idx].y += (float) data->height / 2;
		idx++;
	}
}

t_pointf	ft_genp(t_pointf point, struct s_norm norm, t_data *data)
{
	t_pointf	new;

	new = point;
	new.x = (new.x + ((float) data->width / 2)) - norm.width / 2;
	new.y = (new.y + ((float) data->height / 2)) - norm.height / 2;
	translate(&new, data->view);
	return (new);
}

void	ft_would_dimension(t_data *data, int *height, int *width)
{
	float	fheight;
	float	fwidth;

	ft_to_3d(data);
	ft_calculate_dimensions(data->points_view, data->total_points,
		&fwidth, &fheight);
	*height = (int) fheight;
	*width = (int) fwidth;
}

void	ft_render(t_data *data)
{
	struct s_norm	norm;
	t_pointf		*points;
	t_pointf		point;
	int				idx;

	points = data->points_view;
	ft_to_3d(data);
	ft_calculate_dimensions(points, data->total_points,
		&norm.width, &norm.height);
	ft_fix_points(points, data->total_points);
	norm.img = ft_new_img(data);
	idx = -1;
	while (++idx < data->total_points)
	{
		point = ft_genp(points[idx], norm, data);
		if (idx % data->size < data->size - 1)
			ft_draw_line(&norm.img, point, ft_genp(points[idx + 1],
					norm, data), points[idx].color);
		if (idx / data->size + 1 < data->total_points / data->size)
			ft_draw_line(&norm.img, point, ft_genp(points[idx + data->size],
					norm, data), points[idx + data->size].color);
		ft_set_pixel(&norm.img, point.x, point.y, points[idx].color);
	}
	mlx_put_image_to_window(data->mlx, data->win, norm.img.img, 0, 0);
	return (mlx_destroy_image(data->mlx, norm.img.img), ft_render_text(data));
}
