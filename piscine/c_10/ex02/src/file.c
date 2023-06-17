#include "ft_tail.h"

int	ft_open_file(char *path)
{
	if (ft_strcmp(path, "-") == 0)
	{
		return (STDIN_FILENO);
	}
	return (open(path, O_RDONLY));
}

void	*increase_buff(void *buff, unsigned int buff_size, unsigned int amount)
{
	char				*new_buff;
	unsigned int		idx;

	new_buff = falloc(buff_size + amount);
	if (new_buff == NULL)
		return (NULL);
	idx = 0;
	while (idx < buff_size)
	{
		new_buff[idx] = ((char *) buff)[idx];
		idx++;
	}
	free(buff);
	return (new_buff);
}

int	ft_read_entire_file(int file, char **buffer)
{
	int	total_read;
	int	current_read;

	total_read = 0;
	*buffer = falloc(BUFFER_SIZE);
	current_read = read(file, *buffer, BUFFER_SIZE);
	total_read += current_read;
	while (current_read > 0)
	{
		*buffer = increase_buff(*buffer, total_read, BUFFER_SIZE);
		if (buffer == NULL)
			return (-1);
		current_read = read(file, (*buffer) + total_read, BUFFER_SIZE);
		total_read += current_read;
	}
	if (current_read < 0)
		return (-1);
	return (total_read);
}

void	ft_putfname(char *name, int *first_file)
{
	if (*first_file == -1)
		return ;
	if (*first_file == 0)
		ft_putstr("\n");
	*first_file = 0;
	ft_putstr("==> ");
	if (ft_strcmp(name, "-") == 0)
		ft_putstr("standard input");
	else
		ft_putstr(name);
	ft_putstr(" <==\n");
}

int	ft_write_file_tail(char *exec_name, char *path, int n, int *first_file)
{
	char	*buffer;
	int		file;
	int		buffer_size;

	file = ft_open_file(path);
	if (file < 0)
		return (ft_puterr_open(exec_name, path, errno), 0);
	ft_putfname(path, first_file);
	buffer = NULL;
	buffer_size = ft_read_entire_file(file, &buffer);
	if (buffer == NULL || buffer_size == -1)
		return (ft_puterr_read(exec_name, path, errno), close(file), 0);
	if (n > buffer_size)
		n = buffer_size;
	while (n > 0)
		ft_putchar(buffer[buffer_size - n--]);
	return (close(file), 1);
}
