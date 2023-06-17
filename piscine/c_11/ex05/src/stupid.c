#include "do_op.h"

int	get_stupid_idx(char op)
{
	if (op == '+')
		return (0);
	if (op == '-')
		return (1);
	if (op == '/')
		return (2);
	if (op == '*')
		return (3);
	if (op == '%')
		return (4);
	return (-1);
}

t_stupid	get_operator(char op)
{
	t_stupid	idiot[5];
	int			g_idx;

	g_idx = get_stupid_idx(op);
	if (g_idx < 0)
		return (NULL);
	idiot[0] = &addition;
	idiot[1] = &subtraction;
	idiot[2] = &division;
	idiot[3] = &multiplication;
	idiot[4] = &modulo;
	return (idiot[g_idx]);
}
