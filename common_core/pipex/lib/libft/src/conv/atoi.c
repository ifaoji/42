/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	bool	is_negative;
	int		result;

	is_negative = false;
	result = 0;
	while (*nptr && ft_isspace(*nptr))
		++nptr;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			is_negative = true;
	while (*nptr >= '0' && *nptr <= '9')
		result = result * 10 + *(nptr++) - '0';
	if (is_negative)
		result *= -1;
	return (result);
}
