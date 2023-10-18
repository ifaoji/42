/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_r(t_node **stack)
{
	t_node	*first;
	t_node	*tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	first->next = NULL;
}

/** Shift up all elements of stack a by 1.
 *  The first element becomes the last one.
 */
void	ft_ra(t_node **stack_a)
{
	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	ft_r(stack_a);
	ft_putendl_fd("ra", STDOUT_FILENO);
}

/** Shift up all elements of stack b by 1.
 *  The first element becomes the last one.
 */
void	ft_rb(t_node **stack_b)
{
	if (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	ft_r(stack_b);
	ft_putendl_fd("rb", STDOUT_FILENO);
}

/** ra and rb at the same time.
 *  Shift up all elements of both stacks by 1.
 *  The first element becomes the last one.
 */
void	ft_rr(t_node **stack_a, t_node **stack_b)
{
	ft_r(stack_a);
	ft_r(stack_b);
	ft_putendl_fd("rr", STDOUT_FILENO);
}
