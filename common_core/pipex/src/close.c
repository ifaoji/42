/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close(t_data *data, t_exit_code code)
{
	t_pids	*tmp;

	if (data->paths)
		ft_free_stra(data->paths);
	while (data->pids)
	{
		tmp = data->pids;
		data->pids = data->pids->next;
		(void) tmp;
		free(tmp);
	}
	exit(code);
}
