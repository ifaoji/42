#include "ft_display_file.h"

void	ft_puterrstr(char *str)
{
	while (*str)
		write(STDERR_FILENO, str++, 1);
}

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
