/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_s(t_node **stack)
{
	t_node	*tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

/** Swap the first 2 elements at the top of stack a.
 *  Do nothing if there is only one or no elements.
 */
void	ft_sa(t_node **stack_a)
{
	ft_s(stack_a);
	ft_putendl_fd("sa", STDOUT_FILENO);
}

/** Swap the first 2 elements at the top of stack b.
 *  Do nothing if there is only one or no elements.
 */
void	ft_sb(t_node **stack_b)
{
	ft_s(stack_b);
	ft_putendl_fd("sb", STDOUT_FILENO);
}

/** sa and sb at the same time.
 *  Swap the first 2 elements at the top of both stacks.
 *  Stacks with only one or no elements get skiped.
 */
void	ft_ss(t_node **stack_a, t_node **stack_b)
{
	ft_s(stack_a);
	ft_s(stack_b);
	ft_putendl_fd("ss", STDOUT_FILENO);
}
