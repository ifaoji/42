#include "ft_hexdump.h"

void	ft_putbuffer(unsigned char *buffer, int amount)
{
	int	idx;

	idx = 0;
	while (idx < amount)
	{
		write(STDOUT_FILENO, &buffer[idx], 1);
		idx++;
	}
}

void	ft_putstr(char *str)
{
	while (*str)
		write(STDOUT_FILENO, str++, 1);
}

void	ft_put_writable(char c)
{
	if (c >= 32 && c <= 126)
	{
		write(1, &c, 1);
		return ;
	}
	write(1, ".", 1);
}

void	ft_puterrstr(char *str)
{
	while (*str)
		write(STDERR_FILENO, str++, 1);
}

void	ft_puterr(t_state *state, t_error error)
{
	ft_puterrstr(state->bin_name);
	ft_puterrstr(": ");
	if (error == ALL_FAILED)
	{
		ft_puterrstr("all input file arguments failed\n");
		return ;
	}
	if (error == STD_ERR)
	{
		ft_puterrstr(state->files[state->file_idx]);
		ft_puterrstr(": ");
		ft_puterrstr(strerror(errno));
		ft_puterrstr("\n");
	}
	if (error == OPEN_DIR)
	{
		ft_puterrstr(state->files[state->file_idx]);
		ft_puterrstr(": ");
		ft_puterrstr("Is a directory");
		ft_puterrstr("\n");
	}
}
