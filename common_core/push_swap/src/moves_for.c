/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_for.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ft_moves_for_1(t_node *stack, t_node *node,
	t_node *best, int smallest)
{
	return (
		(
			(
				stack->next
				&& stack->value > node->value
				&& stack->next->value < node->value
			)
			&& (
				best == NULL
				|| stack->value > best->value)
		)
		|| (
			smallest > node->value
			&& stack->value > node->value
			&& (best == NULL || stack->value < best->value)
		)
	);
}

static bool	ft_moves_for_2(t_node *stack, t_node *node,
	t_node *best, int biggest)
{
	return (
		biggest < node->value
		&& stack->value < node->value
		&& (
			best == NULL
			|| stack->value > best->value
		)
	);
}

static int	best_for(t_node *stack, t_node *node, int smallest, int biggest)
{
	int		idx;
	int		moves;
	t_node	*best;

	idx = -1;
	moves = 0;
	best = NULL;
	while (stack && ++idx >= 0)
	{
		if (ft_moves_for_1(stack, node, best, smallest))
		{
			best = stack;
			moves = idx + 1;
		}
		else if (ft_moves_for_2(stack, node, best, biggest))
		{
			best = stack;
			moves = idx;
		}
		stack = stack->next;
	}
	return (moves);
}

int	ft_moves_for(t_node *stack, int size, t_node *node)
{
	int	smallest;
	int	biggest;
	int	moves;

	smallest = ft_smallest(stack);
	biggest = ft_biggest(stack);
	moves = best_for(stack, node, smallest, biggest);
	if (moves > size / 2)
		return ((size - moves) * -1);
	return (moves);
}
