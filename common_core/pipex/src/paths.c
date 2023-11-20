/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_get_paths(void)
{
	const char	*var;
	char		**paths;

	var = ft_get_env("PATH");
	if (var == NULL)
		return (ft_calloc(1, sizeof(char *)));
	paths = ft_split(var, ':');
	return (paths);
}

static char	*ft_path_join(const char *path1, const char *path2)
{
	char	*str;
	char	*tmp;

	if (path1 == NULL || path2 == NULL)
		return (NULL);
	str = malloc(ft_strlen(path1) + 1 + ft_strlen(path2) + 1);
	if (str == NULL)
		return (NULL);
	tmp = str;
	while (*path1)
		*tmp++ = *path1++;
	*tmp++ = '/';
	while (*path2)
		*tmp++ = *path2++;
	*tmp = '\0';
	return (str);
}

char	*ft_find_cmd_path(const char *paths[], const char *cmd)
{
	int		idx;
	char	*path;

	if (ft_strchr(cmd, '/') || paths[0] == NULL)
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	idx = 0;
	while (paths[idx])
	{
		path = ft_path_join(paths[idx], cmd);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		idx++;
	}
	return (NULL);
}
