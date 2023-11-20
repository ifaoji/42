/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	if (little[0] == '\0')
		return ((char *) big);
	little_len = ft_strlen(little);
	while (true)
	{
		if (len < 1 || *big == '\0' || little_len > len)
			return (NULL);
		len--;
		if (*big != little[0])
		{
			big++;
			continue ;
		}
		if (ft_strncmp(big, little, little_len) == 0)
			break ;
		big++;
	}
	return ((char *)big);
}
