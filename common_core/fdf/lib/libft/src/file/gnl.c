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

static int	handle_read(t_lsti *item, t_line *line)
{
	item->size = read(item->fd, item->cache, BUFFER_SIZE);
	if (item->size < 0)
	{
		free(line->data);
		line->data = NULL;
		return (ft_gnl_del_cached(item->fd), -1);
	}
	if (item->size == 0)
		return (ft_gnl_del_cached(item->fd), 1);
	item->offset = 0;
	line->idx = 0;
	return (0);
}

static int	handle_data(t_lsti *item, t_line *line)
{
	if (line->idx + item->offset >= item->size)
	{
		append_line(line,
			&item->cache[item->offset], item->size - item->offset);
		if (line->data == NULL)
			return (ft_gnl_del_cached(item->fd), -1);
		line->current_size += item->size - item->offset;
		item->size = 0;
		return (0);
	}
	if (item->cache[item->offset + line->idx] == '\n'
		|| item->cache[item->offset + line->idx] == '\0')
	{
		append_line(line, &item->cache[item->offset], line->idx + 1);
		if (line->data == NULL)
			return (ft_gnl_del_cached(item->fd), -1);
		item->offset += line->idx + 1;
		return (1);
	}
	return (0);
}

int	ft_gnl(int fd, char **dst)
{
	t_lsti			*item;
	t_line			line;
	int				result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	item = ft_gnl_get_cached(fd);
	if (item == NULL)
		return (-1);
	line.current_size = 0;
	line.data = NULL;
	line.idx = 0;
	while (true)
	{
		if (item->offset >= item->size)
		{
			result = handle_read(item, &line);
			if (result != 0)
				return (*dst = line.data, result);
		}
		result = handle_data(item, &line);
		if (result != 0)
			return (*dst = line.data, result);
		line.idx++;
	}
}
