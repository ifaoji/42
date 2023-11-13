/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_calculate_dimensions(t_pointf *points, int point_amount,
			float *width, float *height)
{
	float	min_x;
	float	min_y;
	float	max_x;
	float	max_y;
	int		i;

	min_x = 1e9;
	min_y = 1e9;
	max_x = -1e9;
	max_y = -1e9;
	i = 0;
	while (i < point_amount)
	{
		if (points[i].x < min_x)
			min_x = points[i].x;
		if (points[i].y < min_y)
			min_y = points[i].y;
		if (points[i].x > max_x)
			max_x = points[i].x;
		if (points[i].y > max_y)
			max_y = points[i].y;
		i++;
	}
	*width = max_x - min_x;
	*height = max_y - min_y;
}
