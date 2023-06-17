#include "ft_hexdump.h"

void	ft_print_hex(int c, int min_length)
{
	if (c / 16 > 0)
		ft_print_hex(c / 16, min_length - 1);
	else
	{
		while (--min_length > 0)
			write(1, "0", 1);
	}
	c %= 16;
	if (c <= 9)
		c += '0';
	else
		c += 'a' - 10;
	write(1, &c, 1);
}

void	ft_print_strange(unsigned char buff[], int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		ft_print_hex(buff[idx + 1], 2);
		ft_print_hex(buff[idx], 2);
		if (idx < size - 2)
			ft_putstr(" ");
		idx += 2;
	}
	while (idx < 16)
	{
		ft_putstr("  ");
		ft_putstr("   ");
		if (idx < size - 2)
			ft_putstr(" ");
		idx += 2;
	}
}

void	ft_print_normal(unsigned char buff[], int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		ft_print_hex(buff[idx], 2);
		if (idx++ == 7)
			ft_putstr(" ");
		ft_putstr(" ");
	}
	while (idx < 16)
	{
		ft_putstr("  ");
		if (idx++ == 7)
			ft_putstr(" ");
		ft_putstr(" ");
	}
	ft_putstr(" |");
	idx = 0;
	while (idx < size)
		ft_put_writable(buff[idx++]);
	ft_putstr("|");
}

bool	ft_bufcmp(unsigned char s1[], unsigned char s2[])
{
	int	idx;

	idx = 0;
	while (idx < 16)
	{
		if (s1[idx] != s2[idx])
			return (false);
		idx++;
	}
	return (true);
}

void	ft_print_line(t_state *state, unsigned char buffer[], int buff_size)
{
	if (ft_bufcmp(state->last_write, buffer))
	{
		if (!state->wrote_star)
			ft_putstr("*\n");
		state->wrote_star = true;
		return ;
	}
	state->wrote_star = false;
	if (state->is_c)
	{
		ft_print_hex(state->offset, 8);
		ft_putstr("  ");
		ft_print_normal(buffer, buff_size);
	}
	else
	{
		ft_print_hex(state->offset, 7);
		ft_putstr(" ");
		ft_print_strange(buffer, buff_size);
	}
	ft_putstr("\n");
}
