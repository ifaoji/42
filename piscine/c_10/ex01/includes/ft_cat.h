/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H
# include <errno.h>
# include <fcntl.h>
# include <libgen.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

# define BUFFER_SIZE 3000

// Console printing (console.c)
void	ft_putbuffer(char *buffer, int amount);
void	ft_puterrstr(char *str);
void	ft_puterr(char *bin_name, char *file, int errnum);

// File handling (file.c)
int		ft_open_file(char *path);
int		ft_close_file(int file_descriptor);
int		ft_read_file(int file_descriptor, void *buffer, size_t count);
int		ft_write_file(char *path);

// String utilities (string.c)
int		ft_strcmp(char *s1, char *s2);

#endif
