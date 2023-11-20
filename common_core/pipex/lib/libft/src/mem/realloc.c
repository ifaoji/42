/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc_del(void *ptr, size_t current_size, size_t new_size,
	void del (void *))
{
	unsigned char	*new;
	size_t			idx;
	size_t			to_copy;

	if (ptr == NULL)
		return (ft_calloc(new_size, 1));
	if (new_size == 0)
		return (del(ptr), NULL);
	new = ft_calloc(new_size, 1);
	if (new == NULL)
		return (del(ptr), NULL);
	idx = 0;
	to_copy = ft_minlu(current_size, new_size);
	while (idx < to_copy)
	{
		new[idx] = ((unsigned char *)ptr)[idx];
		idx++;
	}
	free(ptr);
	return (new);
}

void	*ft_realloc(void *ptr, size_t current_size, size_t new_size)
{
	return (ft_realloc_del(ptr, current_size, new_size, free));
}
