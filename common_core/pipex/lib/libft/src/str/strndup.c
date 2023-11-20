/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*cpy;
	size_t	idx;

	n = ft_minlu(ft_strlen(src), n);
	cpy = malloc(n + 1);
	if (cpy == NULL)
		return (NULL);
	idx = 0;
	while (src[idx] && idx < n)
	{
		cpy[idx] = src[idx];
		idx++;
	}
	cpy[idx] = '\0';
	return (cpy);
}
