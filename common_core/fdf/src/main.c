/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_cap_rend(t_data *data)
{
	int	width;
	int	height;
	int	width_scale;
	int	height_scale;

	ft_would_dimension(data, &height, &width);
	width_scale = ((float) data->width / (float) width) * 30;
	height_scale = ((float) data->height / (float) height) * 30;
	data->view.scale = ft_min(ft_min(width_scale, height_scale), 100);
	data->view.scale = ft_max(data->view.scale, 0);
}

bool	ft_init_data(t_data *data)
{
	int	sizex;
	int	sizey;

	data->view.scale = 30;
	data->view.rotate_x = 72;
	data->view.rotate_y = 330;
	data->view.rotate_z = 0;
	data->view.move_x = 0;
	data->view.move_y = 0;
	data->view.move_z = 1;
	data->view.parralel_projection = false;
	data->view.render_text = true;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (false);
	data->height = 0;
	data->width = 0;
	ft_would_dimension(data, &data->height, &data->width);
	mlx_get_screen_size(data->mlx, &sizex, &sizey);
	data->width = ft_max(ft_min(data->width + 100, sizex - 100), sizex / 2);
	data->height = ft_max(ft_min(data->height + 100, sizey - 100), sizey / 2);
	ft_cap_rend(data);
	data->win = mlx_new_window(data->mlx, data->width, data->height, "FDF");
	return (data->win != NULL);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_pointf	**points_matrix;

	data.mlx = NULL;
	data.points = NULL;
	data.points_view = NULL;
	data.size = ft_parse_args(argc, argv, &points_matrix);
	if (data.size == 0)
		return (1);
	data.points = ft_pm2a(points_matrix, data.size, &data.total_points);
	ft_free_matrix((void **) points_matrix);
	if (data.points == NULL)
		return (perror("Error"), ft_close(&data, 1), 1);
	data.points_view = ft_calloc(data.total_points, sizeof(t_pointf));
	if (data.points_view == NULL)
		return (perror("Error"), ft_close(&data, 1), 1);
	if (ft_init_data(&data) == false)
		return (perror("Error"), ft_close(&data, 1), 1);
	mlx_hook(data.win, DestroyNotify, 0, ft_close, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, handle_key, &data);
	mlx_mouse_hook(data.win, handle_mouse, &data);
	ft_render(&data);
	mlx_loop(data.mlx);
}
