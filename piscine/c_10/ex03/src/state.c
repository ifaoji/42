#include "ft_hexdump.h"

t_state	ft_create_state(int file_count, char **files, char *bin_name)
{
	t_state	state;

	state.one_succeed = false;
	state.wrote_star = false;
	state.files = files;
	state.file_count = file_count;
	state.file_idx = 0;
	state.current_file = -1;
	state.file_offset = 0;
	state.offset = 0;
	state.bin_name = basename(bin_name);
	state.is_c = false;
	return (state);
}
