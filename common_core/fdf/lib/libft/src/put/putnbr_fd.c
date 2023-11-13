/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	unsigned int	divider;
	unsigned int	num;
	char			tmp;
	int				written;

	divider = 1000000000;
	num = n;
	written = 0;
	if (n < 0)
	{
		written += write(fd, "-", 1);
		num = -n;
	}
	while (divider > num && divider != 1)
		divider /= 10;
	while (true)
	{
		tmp = '0' + (num / divider);
		written += write(fd, &tmp, 1);
		num = num % divider;
		if (divider == 1)
			break ;
		divider /= 10;
	}
	return (written);
}
