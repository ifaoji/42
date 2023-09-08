/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char			*tmp;
	int				dest_len;
	int				idx;

	tmp = dst;
	while (tmp && *tmp && size > 0)
	{
		tmp++;
		size--;
	}
	if (size == 0)
		return (tmp - dst + ft_strlen(src));
	dest_len = tmp - dst;
	idx = 0;
	while (size-- > 1 && src[idx])
		*tmp++ = src[idx++];
	*tmp = '\0';
	return (dest_len + ft_strlen(src));
}
