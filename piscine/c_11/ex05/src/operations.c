#include "do_op.h"

bool	addition(t_state *state)
{
	state->result = state->a + state->b;
	return (true);
}

bool	subtraction(t_state *state)
{
	state->result = state->a - state->b;
	return (true);
}

bool	division(t_state *state)
{
	if (state->b == 0)
	{
		state->error = DIV_ZERO;
		return (false);
	}
	state->result = state->a / state->b;
	return (true);
}

bool	multiplication(t_state *state)
{
	state->result = state->a * state->b;
	return (true);
}

bool	modulo(t_state *state)
{
	if (state->b == 0)
	{
		state->error = MOD_ZERO;
		return (false);
	}
	state->result = state->a % state->b;
	return (true);
}
