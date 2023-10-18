/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/inc/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	struct s_node	*next;
	int				value;
}	t_node;

typedef struct s_moves
{
	struct s_node	*node;
	int				sa;
	int				sb;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
}	t_moves;

enum	e_error
{
	DUPLICATED_NUMBER = 0,
	MALLOC_FAILED = 1,
	PARSING_ARGS = 2,
	INVALID_INSTRUCTION = 3,
};

// args.c
int		ft_parse_args(int **dest, int argc, char **argv);

// biggest_smallest.c
int		ft_biggest(t_node *stack);
int		ft_smallest(t_node *stack);

// calculate_moves.c
t_moves	*ft_calculate_distance(t_node *stack_a, t_node *stack_b, t_node *node);

// create_stack.c
t_node	*ft_create_stack(int argc, char **argv);

// final_up.c
void	ft_final_rotate(t_node **stack_a);

// free.c
void	ft_free_matrix(void **matrix, void (*del)(void *));
void	ft_free_stack(t_node *stack);

// is_sorted.c
bool	ft_is_sorted(t_node *stack);

// merge.c
void	ft_merge(t_node **stack_a, t_node **stack_ba);

// min.c
int		ft_min(int a, int b);

// moves_for.c
int		ft_moves_for(t_node *stack, int size, t_node *node);

// moves_to_top.c
int		ft_moves_to_top(t_node *stack_b, t_node *node);

// move_unsorted.c
bool	ft_move_unsorted(t_node **stack_a, t_node **stack_b);

// panic.c
void	ft_panic(enum e_error err);

// push.c
void	ft_p(t_node **source, t_node **target);
void	ft_pa(t_node **stack_a, t_node **stack_b);
void	ft_pb(t_node **stack_a, t_node **stack_b);

// reverse_rotate.c
void	ft_revr(t_node **stack);
void	ft_rra(t_node **stack_a);
void	ft_rrb(t_node **stack_b);
void	ft_rrr(t_node **stack_a, t_node **stack_b);

// rotate.c
void	ft_r(t_node **stack);
void	ft_ra(t_node **stack_a);
void	ft_rb(t_node **stack_b);
void	ft_rr(t_node **stack_a, t_node **stack_b);

// sort_5.c
void	ft_sort_5(t_node **stack_a, t_node **stack_b);

// stack_size.c
int		ft_stack_size(t_node *stack);

// swap.c
void	ft_s(t_node **stack);
void	ft_sa(t_node **stack_a);
void	ft_sb(t_node **stack_b);
void	ft_ss(t_node **stack_a, t_node **stack_b);

#endif
