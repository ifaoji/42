#include "ft_display_file.h"

int	ft_close_file(int file_descriptor)
{
	return (close(file_descriptor));
}

int	ft_open_file(int argc, char **argv)
{
	int	file_descriptor;

	if (argc == 1)
	{
		ft_puterrstr("File name missing.\n");
		return (-1);
	}
	if (argc > 2)
	{
		ft_puterrstr("Too many arguments.\n");
		return (-1);
	}
	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		ft_puterrstr("Cannot read file.\n");
		return (-1);
	}
	return (file_descriptor);
}

int	ft_read_file(int file_descriptor, void *buffer, size_t count)
{
	return (read(file_descriptor, buffer, count));
}

void	clear_buffer(char *buffer, int size)
{
	while (--size >= 0)
		buffer[size] = 0;
}

void	ft_write_file(int file_descriptor)
{
	char	buffer[1024];
	int		read_amount;

	read_amount = ft_read_file(file_descriptor, buffer, 1024);
	while (read_amount > 0)
	{
		ft_putbuffer(buffer, read_amount);
		clear_buffer(buffer, read_amount);
		read_amount = ft_read_file(file_descriptor, buffer, 1024);
	}
}
