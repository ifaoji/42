#include "ft_cat.h"

int	ft_close_file(int file_descriptor)
{
	return (close(file_descriptor));
}

int	ft_open_file(char *path)
{
	if (ft_strcmp(path, "-") == 0)
	{
		return (STDIN_FILENO);
	}
	return (open(path, O_RDONLY));
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

int	ft_write_file(char *path)
{
	char	buffer[BUFFER_SIZE];
	int		file;
	int		read_amount;

	clear_buffer(buffer, BUFFER_SIZE);
	file = ft_open_file(path);
	if (file < 0)
		return (0);
	read_amount = ft_read_file(file, buffer, BUFFER_SIZE);
	while (read_amount > 0)
	{
		ft_putbuffer(buffer, read_amount);
		clear_buffer(buffer, read_amount);
		read_amount = ft_read_file(file, buffer, BUFFER_SIZE);
	}
	if (read_amount < 0)
		return (0);
	return (1);
}
