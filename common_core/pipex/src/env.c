/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// `name_len + 1` because env is stored like `KEY=VALUE`
// and we only want `VALUE`
const char	*ft_get_env(const char *name)
{
	int	name_len;
	int	idx;

	if (name == NULL)
		return (NULL);
	name_len = ft_strlen(name);
	idx = -1;
	while (environ[++idx] != NULL)
	{
		if (environ[idx][name_len] != '=')
			continue ;
		if (ft_strncmp(environ[idx], name, name_len) != 0)
			continue ;
		break ;
	}
	if (environ[idx] == NULL)
		return (NULL);
	return (&environ[idx][name_len + 1]);
}
