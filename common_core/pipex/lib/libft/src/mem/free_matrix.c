/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_matrix(void **matrix)
{
	int	idx;

	if (matrix == NULL)
		return ;
	idx = 0;
	while (matrix[idx])
		free(matrix[idx++]);
	free(matrix);
}

void	ft_free_matrix_del(void **matrix, void del (void *))
{
	int	idx;

	if (matrix == NULL)
		return ;
	idx = 0;
	while (matrix[idx])
		del(matrix[idx++]);
	free(matrix);
}
