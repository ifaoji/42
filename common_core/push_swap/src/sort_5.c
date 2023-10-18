/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_3(t_node **stack)
{
	int	a;
	int	b;
	int	c;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	a = (*stack)->value;
	b = (*stack)->next->value;
	if (a > b && (*stack)->next->next == NULL)
		return (ft_sa(stack));
	if ((*stack)->next->next == NULL)
		return ;
	c = (*stack)->next->next->value;
	if (b > a && b > c && c > a)
		return (ft_sa(stack), ft_ra(stack));
	if (a > b && a < c)
		return (ft_sa(stack));
	if (b > a && b > c && a > c)
		return (ft_rra(stack));
	if (a > b && a > c && c > b)
		return (ft_ra(stack));
	if (a > b && a > c && b > c)
		return (ft_sa(stack), ft_rra(stack));
}

static void	ft_pop_smallest(t_node **stack_a, int size, t_node **stack_b)
{
	t_node	*tmp;
	t_node	*smallest;
	int		idx;
	int		smallest_idx;

	smallest = *stack_a;
	smallest_idx = 0;
	tmp = (*stack_a)->next;
	idx = 0;
	while (tmp && ++idx)
	{
		if (tmp->value < smallest->value)
		{
			smallest = tmp;
			smallest_idx = idx;
		}
		tmp = tmp->next;
	}
	if (smallest_idx < size / 2)
		while (smallest_idx-- > 0)
			ft_ra(stack_a);
	else
		while (smallest_idx++ < size)
			ft_rra(stack_a);
	ft_pb(stack_a, stack_b);
}

void	ft_sort_5(t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = ft_stack_size(*stack_a);
	if (size > 5 || size < 3)
		return ;
	if (size >= 4)
		ft_pop_smallest(stack_a, size, stack_b);
	if (size == 5)
		ft_pop_smallest(stack_a, size - 1, stack_b);
	ft_sort_3(stack_a);
	if (size == 3)
		return ;
	ft_pa(stack_a, stack_b);
	if (size == 4)
		return ;
	ft_pa(stack_a, stack_b);
}
