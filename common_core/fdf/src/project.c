/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	project(t_pointf *point, float focal_length, float distance_to_camera)
{
	float	f;
	float	d;

	f = focal_length;
	d = distance_to_camera;
	point->x = (point->x * f) / (point->z + d);
	point->y = (point->y * f) / (point->z + d);
	point->z = (point->z * f) / (point->z + d);
}
