/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_cache.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_lsti	**ft_gnl_cache(void)
{
	static t_lsti	*cache = NULL;

	return (&cache);
}

t_lsti	*ft_gnl_get_cached(int fd)
{
	t_lsti			**cache;
	t_lsti			*item;
	t_lsti			*tmp;

	cache = ft_gnl_cache();
	tmp = *cache;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (tmp && tmp->fd == fd)
		return (tmp);
	item = ft_calloc(1, sizeof(t_lsti));
	if (item == NULL)
		return (NULL);
	item->fd = fd;
	item->size = 0;
	item->offset = BUFFER_SIZE;
	item->next = NULL;
	return (item->next = *cache, *cache = item);
}

void	ft_gnl_del_cached(int fd)
{
	t_lsti	**cache;
	t_lsti	*current;
	t_lsti	*previous;

	cache = ft_gnl_cache();
	current = *cache;
	previous = NULL;
	while (current && current->fd != fd)
	{
		previous = current;
		current = current->next;
	}
	if (current == NULL || current->fd != fd)
		return ;
	if (previous == NULL)
		*cache = current->next;
	else
		previous->next = current->next;
	free(current);
}

void	ft_gnl_clear_cache(void)
{
	t_lsti	**cache;
	t_lsti	*current;
	t_lsti	*tmp;

	cache = ft_gnl_cache();
	current = *cache;
	*cache = NULL;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
}
