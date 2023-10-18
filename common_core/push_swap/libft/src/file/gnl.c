/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	append_line(t_line *line, char *data, ssize_t amount)
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

static bool	handle_read(t_lsti *item, t_line *line)
{
	item->size = read(item->fd, item->cache, BUFFER_SIZE);
	if (item->size < 0)
	{
		free(line->data);
		line->data = NULL;
	}
	if (item->size <= 0)
		return (ft_gnl_del_cached(item->fd), true);
	item->offset = 0;
	line->idx = 0;
	return (false);
}

static bool	handle_data(t_lsti *item, t_line *line)
{
	if (line->idx + item->offset >= item->size)
	{
		append_line(line,
			&item->cache[item->offset], item->size - item->offset);
		if (line->data == NULL)
			return (ft_gnl_del_cached(item->fd), true);
		line->current_size += item->size - item->offset;
		item->size = 0;
		return (false);
	}
	if (item->cache[item->offset + line->idx] == '\n'
		|| item->cache[item->offset + line->idx] == '\0')
	{
		append_line(line, &item->cache[item->offset], line->idx + 1);
		if (line->data == NULL)
			return (ft_gnl_del_cached(item->fd), true);
		item->offset += line->idx + 1;
		return (true);
	}
	return (false);
}

char	*ft_gnl(int fd)
{
	t_lsti			*item;
	t_line			line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	item = ft_gnl_get_cached(fd);
	if (item == NULL)
		return (NULL);
	line.current_size = 0;
	line.data = NULL;
	line.idx = 0;
	while (true)
	{
		if (item->offset >= item->size && handle_read(item, &line))
			return (line.data);
		if (handle_data(item, &line))
			return (line.data);
		line.idx++;
	}
}
