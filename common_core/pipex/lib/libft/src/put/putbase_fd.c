/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putbase_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putbase_fd(uint64_t num, const char *base_chars, int fd)
{
	uint64_t	base;
	int			written;

	base = ft_strlen(base_chars);
	written = 0;
	if (num >= base)
		written += ft_putbase_fd(num / base, base_chars, fd);
	written += write(fd, &base_chars[num % base], 1);
	return (written);
}
