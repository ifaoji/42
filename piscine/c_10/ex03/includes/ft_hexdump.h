/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H
# include <errno.h>
# include <fcntl.h>
# include <libgen.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define BUFFER_SIZE 16

typedef struct s_state
{
	bool			one_succeed;
	bool			wrote_star;
	unsigned char	last_write[BUFFER_SIZE];
	char			**files;
	int				file_count;
	int				file_idx;
	int				current_file;
	int				file_offset;
	int				offset;
	char			*bin_name;
	bool			is_c;
}	t_state;

typedef enum e_error
{
	ALL_FAILED,
	STD_ERR,
	OPEN_DIR,
}	t_error;

// Console printing (console.c)
void	ft_putbuffer(unsigned char *buffer, int amount);
void	ft_putstr(char *str);
void	ft_put_writable(char c);
void	ft_puterrstr(char *str);
void	ft_puterr(t_state *state, t_error error);

// Hexdump (dump.c)
void	ft_print_line(t_state *state, unsigned char buffer[], int read_count);
void	ft_print_hex(int c, int min_length);

// File handling (file.c)
bool	ft_process(t_state *state);

// String utilities (string.c)
int		ft_strcmp(char *s1, char *s2);

// State (state.c)
void	ft_free_state(t_state *state);
t_state	ft_create_state(int file_count, char **files, char *bin_name);

// Memory stuff
void	*falloc(unsigned long bytes);

#endif
