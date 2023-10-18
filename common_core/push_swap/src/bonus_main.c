/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_bonus.h"
#include <unistd.h>

static void	ft_free_everything(t_inst *inst, t_node *stack_a, t_node *stack_b)
{
	t_inst	*tmp;

	ft_gnl_del_cached(STDIN_FILENO);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	if (inst == NULL)
		return ;
	while (inst)
	{
		tmp = inst->next;
		free(inst->inst);
		free(inst);
		inst = tmp;
	}
}

static void	ft_collect_inst(t_node *stack_a, t_inst **inst)
{
	t_inst	*tmp;
	t_inst	*new_node;
	char	*line;

	line = ft_gnl(STDIN_FILENO);
	while (line != NULL)
	{
		new_node = ft_calloc(1, sizeof(t_inst));
		if (new_node == NULL)
			return (free(line), ft_free_everything(*inst, stack_a, NULL),
				ft_panic(MALLOC_FAILED));
		new_node->inst = line;
		if ((*inst) == NULL)
		{
			(*inst) = new_node;
			tmp = new_node;
		}
		else
		{
			tmp->next = new_node;
			tmp = tmp->next;
		}
		line = ft_gnl(STDIN_FILENO);
	}
}

static bool	ft_run_cmd(char *cmd, t_node **stack_a, t_node **stack_b)
{
	if (ft_strncmp("sa\n", cmd, 3) == 0)
		return (ft_s(stack_a), true);
	if (ft_strncmp("sb\n", cmd, 3) == 0)
		return (ft_s(stack_b), true);
	if (ft_strncmp("ss\n", cmd, 3) == 0)
		return (ft_s(stack_a), ft_s(stack_b), true);
	if (ft_strncmp("pa\n", cmd, 3) == 0)
		return (ft_p(stack_b, stack_a), true);
	if (ft_strncmp("pb\n", cmd, 3) == 0)
		return (ft_p(stack_a, stack_b), true);
	if (ft_strncmp("ra\n", cmd, 3) == 0)
		return (ft_r(stack_a), true);
	if (ft_strncmp("rb\n", cmd, 3) == 0)
		return (ft_r(stack_b), true);
	if (ft_strncmp("rr\n", cmd, 3) == 0)
		return (ft_r(stack_a), ft_r(stack_b), true);
	if (ft_strncmp("rra\n", cmd, 4) == 0)
		return (ft_revr(stack_a), true);
	if (ft_strncmp("rrb\n", cmd, 4) == 0)
		return (ft_revr(stack_b), true);
	if (ft_strncmp("rrr\n", cmd, 4) == 0)
		return (ft_revr(stack_a), ft_revr(stack_b), true);
	return (false);
}

static bool	ft_process_inst(t_inst *inst, t_node **stack_a, t_node **stack_b)
{
	t_inst	*tmp;
	bool	valid;

	tmp = inst;
	while (tmp)
	{
		valid = ft_run_cmd(tmp->inst, stack_a, stack_b);
		if (!valid)
			return (ft_free_everything(inst, *stack_a, *stack_b),
				ft_panic(INVALID_INSTRUCTION), false);
		tmp = tmp->next;
	}
	if (*stack_b != NULL)
		return (false);
	return (ft_is_sorted(*stack_a));
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_inst	*inst;
	bool	valid;

	stack_b = NULL;
	inst = NULL;
	stack_a = ft_create_stack(argc, argv);
	if (stack_a == NULL)
		return (0);
	ft_collect_inst(stack_a, &inst);
	valid = ft_process_inst(inst, &stack_a, &stack_b);
	if (valid)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	ft_free_everything(inst, stack_a, stack_b);
}
