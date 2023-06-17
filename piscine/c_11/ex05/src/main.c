#include "do_op.h"

int	main(int argc, char **argv)
{
	t_stupid	operate;
	t_state		state;

	if (argc != 4)
		return (1);
	state.a = ft_atoi(argv[1]);
	state.b = ft_atoi(argv[3]);
	state.result = 0;
	state.error = -1;
	operate = get_operator(argv[2][0]);
	if (operate == NULL)
	{
		ft_putstr("0\n");
		return (0);
	}
	if (operate(&state) == false)
	{
		ft_puterr(state.error);
		return (1);
	}
	ft_putnbr(state.result);
	ft_putstr("\n");
}
