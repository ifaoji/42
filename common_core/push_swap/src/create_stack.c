/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*ft_numbers_to_stack(int *numbers, int size)
{
	t_node	*stack;
	t_node	*previous;
	t_node	*new;
	int		idx;

	idx = 0;
	stack = NULL;
	previous = NULL;
	while (idx < size)
	{
		new = ft_calloc(1, sizeof(t_node));
		if (new == NULL)
			return (ft_free_stack(stack), NULL);
		new->value = numbers[idx++];
		if (stack == NULL)
		{
			stack = new;
			previous = stack;
			continue ;
		}
		previous->next = new;
		previous = new;
	}
	return (stack);
}

t_node	*ft_create_stack(int argc, char **argv)
{
	int		*numbers;
	int		amount;
	t_node	*stack;

	amount = ft_parse_args(&numbers, argc, argv);
	stack = ft_numbers_to_stack(numbers, amount);
	if (stack == NULL)
		return (free(numbers), ft_panic(MALLOC_FAILED), NULL);
	free(numbers);
	return (stack);
}
