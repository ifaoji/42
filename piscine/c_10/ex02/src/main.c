#include "ft_tail.h"

int	mastercheck(int argc, char **argv)
{
	if (real_arg_count(argc, argv) == 1)
		return (-1);
	return (1);
}

int	main(int argc, char **argv)
{
	int	idx;
	int	bytes;
	int	first_file;

	first_file = -1;
	bytes = get_bytes(argc, argv);
	if (bytes <= 0)
		return (1);
	if (argc == 1 || real_arg_count(argc, argv) == 0)
	{
		if (!ft_write_file_tail(argv[0], "-", bytes, &first_file))
			return (1);
		return (0);
	}
	idx = 1;
	first_file = mastercheck(argc, argv);
	while (idx < argc)
	{
		if (ft_strcmp(argv[idx], "-c") == 0)
		{
			idx += 2;
			continue ;
		}
		ft_write_file_tail(argv[0], argv[idx++], bytes, &first_file);
	}
}
