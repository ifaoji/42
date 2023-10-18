/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_unsorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_add_move(t_moves moves)
{
	int	r;
	int	rr;

	r = ft_min(moves.ra, moves.rb);
	rr = ft_min(moves.rra, moves.rrb);
	return (
		r + moves.ra - r + moves.rb - r
		+ rr + moves.rra - rr + moves.rrb - rr
		+ moves.sa + moves.sb
	);
}

static t_moves	*ft_most_optimal_b(t_node *stack_a, t_node *stack_b)
{
	t_node	*tmp;
	t_moves	*best;
	t_moves	*current;

	best = NULL;
	tmp = stack_b;
	while (tmp)
	{
		current = ft_calculate_distance(stack_a, stack_b, tmp);
		if (current == NULL)
			return (free(best), NULL);
		if (best == NULL || ft_add_move(*current) < ft_add_move(*best))
		{
			free(best);
			best = current;
		}
		else
			free(current);
		tmp = tmp->next;
	}
	return (best);
}

static void	ft_execute_moves(t_node **stack_a, t_node **stack_b, t_moves *moves)
{
	while (moves->ra > 0 && moves->rb > 0)
	{
		moves->ra--;
		moves->rb--;
		ft_rr(stack_a, stack_b);
	}
	while (moves->rra > 0 && moves->rrb > 0)
	{
		moves->rra--;
		moves->rrb--;
		ft_rrr(stack_a, stack_b);
	}
	while (moves->rrb-- > 0)
		ft_rra(stack_a);
	while (moves->rb-- > 0)
		ft_ra(stack_a);
	while (moves->rra-- > 0)
		ft_rrb(stack_b);
	while (moves->ra-- > 0)
		ft_rb(stack_b);
	while (moves->sa-- > 0)
		ft_sb(stack_b);
	while (moves->sb-- > 0)
		ft_sa(stack_a);
}

bool	ft_move_unsorted(t_node **stack_a, t_node **stack_b)
{
	int		size;
	t_moves	*moves;

	size = ft_stack_size(*stack_a);
	while (size > 5)
	{
		moves = ft_most_optimal_b(*stack_b, *stack_a);
		if (moves == NULL)
			return (false);
		ft_execute_moves(stack_a, stack_b, moves);
		free(moves);
		ft_pb(stack_a, stack_b);
		size--;
	}
	return (true);
}
