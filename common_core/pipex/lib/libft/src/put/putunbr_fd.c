/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_fd(unsigned int n, int fd)
{
	unsigned int	divider;
	char			tmp;
	int				written;

	divider = 1000000000;
	written = 0;
	while (divider > n && divider != 1)
		divider /= 10;
	while (true)
	{
		tmp = '0' + (n / divider);
		written += write(fd, &tmp, 1);
		n = n % divider;
		if (divider == 1)
			break ;
		divider /= 10;
	}
	return (written);
}
