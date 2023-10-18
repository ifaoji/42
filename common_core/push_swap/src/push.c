/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_p(t_node **source, t_node **target)
{
	t_node	*tmp;

	if (source == NULL || *source == NULL || target == NULL)
		return ;
	tmp = *source;
	*source = (*source)->next;
	tmp->next = *target;
	*target = tmp;
}

/** Take the first element at the top of b and put it at the top of a.
 *  Do nothing if b is empty.
 */
void	ft_pa(t_node **stack_a, t_node **stack_b)
{
	ft_p(stack_b, stack_a);
	ft_putendl_fd("pa", STDOUT_FILENO);
}

/** Take the first element at the top of a and put it at the top of b.
 *  Do nothing if a is empty.
 */
void	ft_pb(t_node **stack_a, t_node **stack_b)
{
	ft_p(stack_a, stack_b);
	ft_putendl_fd("pb", STDOUT_FILENO);
}
