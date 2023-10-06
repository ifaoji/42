/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

bool	handle_read(t_lsti **cache, t_lsti *item, t_line *line)
{
	item->size = read(item->fd, item->cache, BUFFER_SIZE);
	if (item->size < 0)
	{
		free(line->data);
		line->data = NULL;
	}
	if (item->size <= 0)
		return (delete_cached(cache, item->fd), true);
	item->offset = 0;
	line->idx = 0;
	return (false);
}

bool	handle_data(t_lsti *item, t_lsti **cache, t_line *line)
{
	if (line->idx + item->offset >= item->size)
	{
		append_line(line,
			&item->cache[item->offset], item->size - item->offset);
		if (line->data == NULL)
			return (delete_cached(cache, item->fd), true);
		line->current_size += item->size - item->offset;
		item->size = 0;
		return (false);
	}
	if (item->cache[item->offset + line->idx] == '\n'
		|| item->cache[item->offset + line->idx] == '\0')
	{
		append_line(line, &item->cache[item->offset], line->idx + 1);
		if (line->data == NULL)
			return (delete_cached(cache, item->fd), true);
		item->offset += line->idx + 1;
		return (true);
	}
	return (false);
}

char	*get_next_line(int fd)
{
	static t_lsti	*cache = NULL;
	t_lsti			*item;
	t_line			line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	item = get_cached(&cache, fd);
	if (item == NULL)
		return (NULL);
	line.current_size = 0;
	line.data = NULL;
	line.idx = 0;
	while (true)
	{
		if (item->offset >= item->size && handle_read(&cache, item, &line))
			return (line.data);
		if (handle_data(item, &cache, &line))
			return (line.data);
		line.idx++;
	}
}
