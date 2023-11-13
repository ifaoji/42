/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_pointf *point, float angle)
{
	float	theta;
	float	y;
	float	z;

	theta = angle * (M_PI / 180.0);
	y = point->y * cos(theta) + point->z * -sin(theta);
	z = point->y * sin(theta) + point->z * cos(theta);
	point->y = y;
	point->z = z;
}

void	rotate_y(t_pointf *point, float angle)
{
	float	theta;
	float	x;
	float	z;

	theta = angle * (M_PI / 180.0);
	x = point->x * cos(theta) + point->z * sin(theta);
	z = point->x * -sin(theta) + point->z * cos(theta);
	point->x = x;
	point->z = z;
}

void	rotate_z(t_pointf *point, float angle)
{
	float	theta;
	float	x;
	float	y;

	theta = angle * (M_PI / 180.0);
	x = point->x * cos(theta) + point->y * -sin(theta);
	y = point->x * sin(theta) + point->y * cos(theta);
	point->x = x;
	point->y = y;
}
