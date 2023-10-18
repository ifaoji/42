/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_revr(t_node **stack)
{
	t_node	*tmp;
	t_node	*previous;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	previous = NULL;
	tmp = *stack;
	while (tmp->next)
	{
		previous = tmp;
		tmp = tmp->next;
	}
	tmp->next = *stack;
	if (previous != NULL)
		previous->next = NULL;
	*stack = tmp;
}

/** Shift down all elements of stack a by 1.
 *  The last element becomes the first one.
 */
void	ft_rra(t_node **stack_a)
{
	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	ft_revr(stack_a);
	ft_putendl_fd("rra", STDOUT_FILENO);
}

/** Shift down all elements of stack b by 1.
 * The last element becomes the first one.
 */
void	ft_rrb(t_node **stack_b)
{
	if (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	ft_revr(stack_b);
	ft_putendl_fd("rrb", STDOUT_FILENO);
}

// rrr : rra and rrb at the same time.
/** rra and rrb at the same time.
 *  Shift down all elements of both stacks by 1.
 *  The last element becomes the first one.
 */
void	ft_rrr(t_node **stack_a, t_node **stack_b)
{
	ft_revr(stack_a);
	ft_revr(stack_b);
	ft_putendl_fd("rrr", STDOUT_FILENO);
}
