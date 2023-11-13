/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	while (*s1 && ft_strchr(set, *s1))
		++s1;
	len = ft_strlen(s1);
	while (len > 0 && ft_strchr(set, s1[len - 1]))
		--len;
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
		str[len] = s1[len];
	return (str);
}
