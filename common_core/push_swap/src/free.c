/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** Free a matrix.
 *
 *  `del` is the function used to free each item.
 */
void	ft_free_matrix(void **matrix, void (*del)(void *))
{
	int	idx;

	idx = 0;
	while (matrix[idx])
	{
		del(matrix[idx]);
		idx++;
	}
	free(matrix);
}

void	ft_free_stack(t_node *stack)
{
	t_node	*tmp;

	if (stack == NULL)
		return ;
	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
