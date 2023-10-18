/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = ft_create_stack(argc, argv);
	if (stack_a == NULL)
		return (0);
	stack_b = NULL;
	if (ft_is_sorted(stack_a))
		return (ft_free_stack(stack_a), 0);
	if (!ft_move_unsorted(&stack_a, &stack_b))
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		ft_panic(MALLOC_FAILED);
	}
	ft_sort_5(&stack_a, &stack_b);
	ft_merge(&stack_a, &stack_b);
	ft_final_rotate(&stack_a);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
}
