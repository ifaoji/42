#include "ft_display_file.h"

int	main(int argc, char **argv)
{
	int	file;

	file = ft_open_file(argc, argv);
	if (file == -1)
		return (1);
	ft_write_file(file);
	ft_close_file(file);
}
