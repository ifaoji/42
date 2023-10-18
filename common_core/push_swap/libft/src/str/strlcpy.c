/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:11:44 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:18:45 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int				length;

	length = ft_strlen(src);
	if (size == 0)
		return (length);
	while (size-- > 1 && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (length);
}
