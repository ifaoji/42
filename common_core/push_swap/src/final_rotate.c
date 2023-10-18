/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ft_final_up(t_node *stack_a)
{
	int		size;
	t_node	*smallest;
	int		position;
	int		idx;

	size = 0;
	position = 0;
	idx = 0;
	smallest = stack_a;
	while (stack_a)
	{
		idx++;
		if (smallest->value > stack_a->value)
		{
			position = idx;
			smallest = stack_a;
		}
		size++;
		stack_a = stack_a->next;
	}
	if (position > size / 2)
		return (false);
	return (true);
}

void	ft_final_rotate(t_node **stack_a)
{
	int		smallest;
	bool	up;

	if (*stack_a == NULL)
		return ;
	smallest = ft_smallest(*stack_a);
	up = ft_final_up(*stack_a);
	while ((*stack_a)->value != smallest)
	{
		if (!up)
			ft_rra(stack_a);
		else
			ft_ra(stack_a);
	}
}
