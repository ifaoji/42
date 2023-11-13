/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pointf	**ft_realloc_dst(t_pointf ***dst, int idx)
{
	t_pointf	**ptr;

	ptr = ft_realloc_del(*dst, idx * sizeof(t_pointf *),
			(idx + 2) * sizeof(t_pointf *), (void (*)()) ft_free_matrix);
	return (ptr);
}

int	ft_args2(int size, int tmp, t_pointf ***dst, int idx)
{
	if (size == 0)
		ft_putendl_fd("Error: No map data found", STDERR_FILENO);
	if (tmp < 0 && size != -1)
		return (free((*dst)[idx]), (*dst)[idx] = NULL, 0);
	if (tmp != size || size == -1)
		return (free((*dst)[idx]), (*dst)[idx] = NULL,
			ft_putendl_fd("Error: Invalid map data", STDERR_FILENO), 0);
	return (1);
}
