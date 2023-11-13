/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_stra(char **arr)
{
	int	idx;

	if (arr == NULL)
		return ;
	idx = 0;
	while (arr[idx])
		free(arr[idx++]);
	free(arr);
}
