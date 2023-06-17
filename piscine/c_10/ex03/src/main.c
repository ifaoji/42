#include "ft_hexdump.h"

int	main(int argc, char **argv)
{
	int		idx;
	t_state	state;

	state = ft_create_state(argc - 1, argv + 1, argv[0]);
	idx = 1;
	while (idx < argc)
	{
		if (ft_strcmp(argv[idx], "-C") == 0)
		{
			state.is_c = true;
			if (argc == 2)
				state.file_count = 0;
		}
		idx++;
	}
	ft_process(&state);
	if (!state.one_succeed)
	{
		ft_puterr(&state, ALL_FAILED);
	}
}
