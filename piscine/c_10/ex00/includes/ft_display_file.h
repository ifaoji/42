/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISPLAY_FILE_H
# define FT_DISPLAY_FILE_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

// Console printing (console.c)
void	ft_puterrstr(char *str);
void	ft_putbuffer(char *buffer, int amount);

// File handling (file.c)
int		ft_open_file(int argc, char **argv);
int		ft_close_file(int file_descriptor);
int		ft_read_file(int file_descriptor, void *buffer, size_t count);
void	ft_write_file(int file_descriptor);

#endif
