/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ft_moves_for_1(t_node *stack, t_node *node,
	t_node *best, int biggest)
{
	return (
		(
			(
				stack->next != NULL
				&& stack->value < node->value
				&& stack->next->value > node->value
			)
			|| (
				biggest < node->value
				&& stack->value < node->value)
		)
		&& (
			best == NULL
			|| stack->value > best->value
		)
	);
}

static bool	ft_moves_for_2(t_node *stack, t_node *node,
	t_node *best, int smallest)
{
	return (
		(
			smallest > node->value
			&& stack->value > node->value
		)
		&& (
			best == NULL
			|| stack->value < best->value
		)
	);
}

static int	best_for(t_node *stack, t_node *node, int smallest, int biggest)
{
	int		idx;
	int		moves;
	t_node	*best;

	idx = 0;
	moves = 0;
	best = NULL;
	while (stack)
	{
		if (ft_moves_for_1(stack, node, best, biggest))
		{
			best = stack;
			moves = idx + 1;
		}
		else if (ft_moves_for_2(stack, node, best, smallest))
		{
			best = stack;
			moves = idx;
		}
		stack = stack->next;
		idx++;
	}
	return (moves);
}

static int	ft_moves_for_merge(t_node *stack, int size, t_node *node)
{
	int		moves;
	int		smallest;
	int		biggest;

	smallest = ft_smallest(stack);
	biggest = ft_biggest(stack);
	moves = best_for(stack, node, smallest, biggest);
	if (moves > size / 2)
		return ((size - moves) * -1);
	return (moves);
}

void	ft_merge(t_node **stack_a, t_node **stack_b)
{
	int	tmp;

	while (*stack_b)
	{
		tmp = ft_moves_for_merge(*stack_a, ft_stack_size(*stack_a), *stack_b);
		if (tmp > 0)
		{
			while (tmp-- > 0)
				ft_ra(stack_a);
		}
		else
		{
			tmp = tmp * -1;
			while (tmp-- > 0)
				ft_rra(stack_a);
		}
		ft_pa(stack_a, stack_b);
	}
}
