/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H
# include <errno.h>
# include <fcntl.h>
# include <libgen.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define BUFFER_SIZE 3000

// Argument stuff (args.c)
int		real_arg_count(int argc, char **argv);
int		get_bytes(int argc, char **argv);

// Console printing (console.c)
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_puterrstr(char *str);
void	ft_puterr_open(char *exec_name, char *file, int errnum);
void	ft_puterr_read(char *exec_name, char *file, int errnum);

// File handling (file.c)
int		ft_open_file(char *path);
int		ft_write_file_tail(char *exec_name, char *path, int n, int *first_file);

// Memory utilities (memory.c)
void	*falloc(unsigned long bytes);

// String utilities (string.c)
int		ft_strcmp(char *s1, char *s2);

#endif
