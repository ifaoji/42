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

static bool	ft_parse_db(t_pointf *dp, char *raw, int x, int y)
{
	char	**splitted;
	int		idx;

	dp->x = x;
	dp->y = y;
	splitted = ft_split(raw, ',');
	if (splitted == NULL)
		return (false);
	dp->z = ft_atoi(*splitted);
	if (dp->z == 0 && ft_strncmp(*splitted, "0", 1) != 0)
		return (ft_free_stra(splitted), false);
	dp->color = 0xFFFFFF;
	if (splitted[1] == NULL)
		return (ft_free_stra(splitted), true);
	if (ft_strncmp(splitted[1], "0x", 2) != 0)
		return (ft_putendl_fd("Error: Invalid map color", STDERR_FILENO),
			ft_free_stra(splitted), false);
	idx = 1;
	while (splitted[1][++idx])
		splitted[1][idx] = ft_toupper(splitted[1][idx]);
	dp->color = ft_atoi_base(&splitted[1][2], "0123456789ABCDEF");
	return (ft_free_stra(splitted), true);
}

static int	ft_parse_line(char *line, t_pointf **dst, int line_number)
{
	int		size;
	int		idx;
	char	**raw;

	*dst = NULL;
	raw = ft_split(line, ' ');
	free(line);
	if (raw == NULL)
		return (perror("Error"), -1);
	size = 0;
	while (raw[size] && raw[size][0] != '\n')
		size++;
	if (size && size == 0)
		return (ft_free_stra(raw), 0);
	*dst = ft_calloc(size, sizeof(t_pointf));
	if (*dst == NULL)
		return (ft_free_stra(raw), -1);
	idx = 0;
	while (idx < size)
	{
		if (ft_parse_db(&(*dst)[idx], raw[idx], idx, line_number) == false)
			return (ft_free_stra(raw), -1);
		idx++;
	}
	return (ft_free_stra(raw), size);
}

static int	ft_parse_file(int fd, t_pointf ***dst, int size)
{
	char	*line;
	int		result;
	int		idx;
	int		tmp;

	idx = -1;
	size = -1;
	result = ft_gnl(fd, &line);
	while (result == 1 && line != NULL && ++idx >= 0)
	{
		*dst = ft_realloc_dst(dst, idx);
		if (*dst == NULL)
			return (perror("Error"), free(line), ft_gnl_del_cached(fd), 0);
		tmp = ft_parse_line(line, &(*dst)[idx], idx);
		if (size == -1)
			size = tmp;
		if (!ft_args2(size, tmp, dst, idx))
			return (0);
		result = ft_gnl(fd, &line);
	}
	if (result == -1)
		return (0);
	return (ft_gnl_del_cached(fd), size);
}

int	ft_parse_args(int argc, char **argv, t_pointf ***dst)
{
	int	fd;
	int	size;

	*dst = NULL;
	if (argc == 1)
		return (ft_putstr_fd("Usage: ", STDERR_FILENO),
			ft_putstr_fd(argv[0], STDERR_FILENO),
			ft_putstr_fd(" <filename>\n", STDERR_FILENO), 0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (perror("Error"), 0);
	size = ft_parse_file(fd, dst, -1);
	if (size <= 0)
		return (ft_free_matrix((void *) *dst), *dst = NULL,
			ft_gnl_del_cached(fd), 0);
	if (close(fd) < 0)
		return (ft_free_matrix((void *) *dst), 0);
	return (size);
}
