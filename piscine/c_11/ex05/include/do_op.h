/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum t_error
{
	DIV_ZERO,
	MOD_ZERO,
}	t_error;

typedef struct t_state
{
	t_error	error;
	int		a;
	int		b;
	int		result;
}	t_state;

typedef bool	(*t_stupid)(t_state *);

// ATOI
int		ft_atoi(char *str);

// Console printing stuff (console.c)
void	ft_puterr(t_error code);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);

// Operations (operations.c)
bool	addition(t_state *state);
bool	subtraction(t_state *state);
bool	division(t_state *state);
bool	multiplication(t_state *state);
bool	modulo(t_state *state);

// Stupid functions for strange array handling (stupid.c)
bool	(*get_operator(char op))(t_state *);

#endif
