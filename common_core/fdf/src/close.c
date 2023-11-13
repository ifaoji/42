/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_close(t_data *data, int code)
{
	if (data->mlx)
	{
		if (data->win)
			mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->points)
		free(data->points);
	if (data->points_view)
		free(data->points_view);
	exit(code);
}
