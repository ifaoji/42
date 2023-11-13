/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_mouse(int button, int x, int y, t_data *param)
{
	(void) x;
	(void) y;
	if (button == MOUSE_SCROLL_UP)
		param->view.scale = ft_min(param->view.scale + 1, 100);
	if (button == MOUSE_SCROLL_DOWN)
		param->view.scale = ft_max(param->view.scale - 1, 1);
	ft_render(param);
	return (0);
}
