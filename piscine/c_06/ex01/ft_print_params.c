#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main(int argc, char **argv)
{
	int	idx;

	if (argc == 1)
		return (0);
	idx = 1;
	while (idx < argc)
	{
		ft_putstr(argv[idx++]);
		ft_putstr("\n");
	}
	return (0);
}
