#include "ft_cat.h"

int	main(int argc, char **argv)
{
	int	idx;

	if (argc == 1)
	{
		if (!ft_write_file("-"))
		{
			ft_puterr(argv[0], "-", errno);
			return (1);
		}
		return (0);
	}
	idx = 1;
	while (idx < argc)
	{
		if (!ft_write_file(argv[idx]))
		{
			ft_puterr(argv[0], argv[idx], errno);
			return (1);
		}
		idx++;
	}
}
