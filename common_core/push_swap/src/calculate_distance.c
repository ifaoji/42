/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_distance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2012/12/12 12:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2012/12/12 12:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	*ft_calculate_distance(t_node *stack_a, t_node *stack_b, t_node *node)
{
	int		size_a;
	int		tmp;
	t_moves	*moves;

	size_a = ft_stack_size(stack_a);
	moves = ft_calloc(1, sizeof(t_moves));
	if (moves == NULL)
		return (NULL);
	tmp = ft_moves_to_top(stack_b, node);
	if (tmp < 0)
		moves->rrb = tmp * -1;
	else
		moves->rb = tmp;
	tmp = ft_moves_for(stack_a, size_a, node);
	if (tmp < 0)
		moves->rra = tmp * -1;
	else
		moves->ra = tmp;
	return (moves);
}
