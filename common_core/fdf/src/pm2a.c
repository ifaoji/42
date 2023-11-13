/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pm2a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Convert the matrix of pointf to a array of pointf
// so it is easier to use later
t_pointf	*ft_pm2a(t_pointf **data, int length, int *total_points)
{
	t_pointf	*res;
	t_pointf	*tmp;
	int			idx;

	*total_points = 0;
	while (data[*total_points])
		*total_points += 1;
	*total_points *= length;
	res = ft_calloc(*total_points, sizeof(t_pointf));
	if (res == NULL)
		return (NULL);
	tmp = res;
	idx = 0;
	while (data[0])
	{
		*tmp = ft_pointf(data[0][idx].x, data[0][idx].y, data[0][idx].z);
		tmp->color = data[0][idx].color;
		tmp++;
		if (++idx == length)
		{
			idx = 0;
			data++;
		}
	}
	return (res);
}
