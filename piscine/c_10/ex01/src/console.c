#include "ft_cat.h"

void	ft_putbuffer(char *buffer, int amount)
{
	int	idx;

	idx = 0;
	while (idx < amount)
	{
		write(STDOUT_FILENO, &buffer[idx], 1);
		idx++;
	}
}

void	ft_puterrstr(char *str)
{
	while (*str)
		write(STDERR_FILENO, str++, 1);
}

void	ft_puterr(char *exec_name, char *file, int errnum)
{
	ft_puterrstr(basename(exec_name));
	ft_puterrstr(": ");
	ft_puterrstr(file);
	ft_puterrstr(": ");
	ft_puterrstr(strerror(errnum));
	ft_puterrstr("\n");
}
