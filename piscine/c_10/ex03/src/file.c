#include "ft_hexdump.h"
#include <fcntl.h>

void	clear_buffer(unsigned char buffer[BUFFER_SIZE], int size)
{
	while (--size >= 0)
		buffer[size] = 0;
}

void	open_next(t_state *state)
{
	int	dircheck;

	if (state->file_count == 0)
	{
		state->current_file = 0;
		return ;
	}
	if (ft_strcmp(state->files[state->file_idx], "-C") == 0)
		state->file_idx++;
	if (state->file_idx >= state->file_count)
		return ;
	state->current_file = open(state->files[state->file_idx], O_RDONLY);
	if (state->current_file < 0 && state->file_idx < state->file_count)
		ft_puterr(state, STD_ERR);
	dircheck = open(state->files[state->file_idx], O_DIRECTORY | O_RDONLY);
	if (dircheck >= 0)
	{
		ft_puterr(state, OPEN_DIR);
		state->current_file = -1;
		state->one_succeed = true;
	}
	state->file_idx++;
}

int	dynamic_read(t_state *state, unsigned char buffer[BUFFER_SIZE])
{
	int	read_amount;

	read_amount = 0;
	while (true)
	{
		if (state->current_file < 0)
		{
			if (state->current_file > 0)
				close(state->current_file);
			if (state->file_idx >= state->file_count && state->file_count != 0)
				return (read_amount);
			open_next(state);
			continue ;
		}
		read_amount += read(state->current_file,
				buffer + read_amount, BUFFER_SIZE - read_amount);
		if (read_amount == BUFFER_SIZE)
			break ;
		state->current_file = -1;
	}
	return (read_amount);
}

void	ft_buffcpy(unsigned char dest[], unsigned char src[])
{
	int	idx;

	clear_buffer(dest, BUFFER_SIZE);
	idx = 0;
	while (idx < BUFFER_SIZE)
	{
		dest[idx] = src[idx];
		idx++;
	}
}

bool	ft_process(t_state *state)
{
	unsigned char	buffer[BUFFER_SIZE];
	int				read_amount;

	while (true)
	{
		read_amount = dynamic_read(state, buffer);
		if (read_amount <= 0)
			break ;
		state->one_succeed = true;
		ft_print_line(state, buffer, read_amount);
		state->offset += read_amount;
		ft_buffcpy(state->last_write, buffer);
		clear_buffer(buffer, BUFFER_SIZE);
	}
	if (state->one_succeed && state->offset > 0)
	{
		if (state->is_c)
			ft_print_hex(state->offset, 8);
		else
			ft_print_hex(state->offset, 7);
		ft_putstr("\n");
	}
	return (true);
}
