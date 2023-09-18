/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	to_lock;
	size_t	src_len;
	size_t	idx;

	if (s == NULL)
		return (ft_calloc(1, sizeof(char)));
	src_len = ft_strlen(s);
	if (start >= src_len || len == 0)
		return (ft_calloc(1, sizeof(char)));
	to_lock = src_len - start;
	if (to_lock > len)
		to_lock = len;
	substr = malloc(to_lock + 1);
	if (substr == NULL)
		return (NULL);
	s += start;
	idx = 0;
	while (idx < len && *s)
		substr[idx++] = *s++;
	substr[idx] = '\0';
	return (substr);
}
