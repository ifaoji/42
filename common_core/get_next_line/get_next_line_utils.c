/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	alloc;
	char	*blob;
	size_t	idx;

	alloc = nmemb * size;
	if (alloc != 0 && alloc / nmemb != size)
		return (NULL);
	blob = malloc(alloc);
	if (blob == NULL)
		return (NULL);
	idx = 0;
	while (idx < size)
		blob[idx++] = 0;
	return (blob);
}

t_lsti	*get_cached(t_lsti **cache, int fd)
{
	t_lsti			*item;
	t_lsti			*tmp;

	if (cache == NULL)
		return (NULL);
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

void	delete_cached(t_lsti **cache, int fd)
{
	t_lsti	*current;
	t_lsti	*previous;

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

void	append_line(t_line *line, char *data, ssize_t amount)
{
	char	*new;
	ssize_t	idx;

	if (amount == 0)
		return ;
	new = malloc(line->current_size + amount + 1);
	if (new == NULL)
	{
		free(line->data);
		line->data = NULL;
		return ;
	}
	new[line->current_size + amount] = '\0';
	idx = -1;
	while (++idx < line->current_size)
		new[idx] = line->data[idx];
	idx = -1;
	while (++idx < amount)
		new[line->current_size + idx] = data[idx];
	free(line->data);
	line->data = new;
	return ;
}
