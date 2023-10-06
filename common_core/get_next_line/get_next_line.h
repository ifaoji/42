/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct t_lsti {
	int				fd;
	char			cache[BUFFER_SIZE];
	ssize_t			offset;
	ssize_t			size;
	struct t_lsti	*next;
}	t_lsti;

typedef struct t_line
{
	char	*data;
	ssize_t	current_size;
	ssize_t	idx;
}	t_line;

// get_next_line.c
char	*get_next_line(int fd);

// get_next_line_utils.c
t_lsti	*get_cached(t_lsti **cache, int fd);
void	delete_cached(t_lsti **cache, int fd);
void	append_line(t_line *line, char *data, ssize_t amount);

#endif
