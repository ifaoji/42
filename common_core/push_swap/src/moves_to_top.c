/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_to_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_moves_to_top(t_node *stack_b, t_node *node)
{
	int	size;
	int	position;

	size = ft_stack_size(stack_b);
	position = 0;
	while (stack_b && stack_b != node)
	{
		position += 1;
		stack_b = stack_b->next;
	}
	if (stack_b == NULL)
		return (0);
	if (position > size / 2)
		return ((size - position) * -1);
	return (position);
}
