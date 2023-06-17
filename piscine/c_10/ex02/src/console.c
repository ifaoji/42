#include "ft_tail.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(STDOUT_FILENO, str++, 1);
}

void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

void	ft_puterrstr(char *str)
{
	while (*str)
		write(STDERR_FILENO, str++, 1);
}

void	ft_puterr_read(char *exec_name, char *file, int errnum)
{
	ft_puterrstr(basename(exec_name));
	ft_puterrstr(": error reading '");
	if (ft_strcmp(file, "-") == 0)
		ft_puterrstr("standard input");
	else
		ft_puterrstr(file);
	ft_puterrstr("': ");
	ft_puterrstr(strerror(errnum));
	ft_puterrstr("\n");
}

void	ft_puterr_open(char *exec_name, char *file, int errnum)
{
	ft_puterrstr(basename(exec_name));
	ft_puterrstr(": cannot open '");
	if (ft_strcmp(file, "-") == 0)
		ft_puterrstr("standard input");
	else
		ft_puterrstr(file);
	ft_puterrstr("' for reading: ");
	ft_puterrstr(strerror(errnum));
	ft_puterrstr("\n");
}
