/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	divider;
	unsigned int	num;
	char			str[12];
	int				idx;

	idx = 0;
	divider = 1000000000;
	num = n;
	if (n < 0)
	{
		str[idx++] = '-';
		num = -n;
	}
	while (divider > num && divider != 1)
		divider /= 10;
	while (true)
	{
		str[idx++] = '0' + (num / divider);
		num = num % divider;
		if (divider == 1)
			break ;
		divider /= 10;
	}
	str[idx] = '\0';
	return (ft_strdup(str));
}
