/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_add(t_data *data, int pid)
{
	t_pids	*tmp;
	t_pids	*new;

	new = ft_calloc(1, sizeof(t_pids));
	new->next = NULL;
	new->pid = pid;
	if (new == NULL)
		return (perror("Error"), ft_close(data, MALLOC_FAILED));
	if (data->pids == NULL)
	{
		data->pids = new;
		return ;
	}
	tmp = data->pids;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}
