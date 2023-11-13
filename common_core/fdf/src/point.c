/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	ft_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

t_pointf	ft_pointf(float x, float y, float z)
{
	t_pointf	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}
