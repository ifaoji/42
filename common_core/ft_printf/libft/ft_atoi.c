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

static int	is_space(char c)
{
	return (
		c == ' '
		|| c == '\f'
		|| c == '\n'
		|| c == '\r'
		|| c == '\t'
		|| c == '\v'
	);
}

int	ft_atoi(const char *nptr)
{
	bool	is_negative;
	int		result;

	while (*nptr && is_space(*nptr))
		++nptr;
	is_negative = false;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			is_negative = true;
		++nptr;
	}
	result = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result *= 10;
		if (is_negative == true)
			result -= *(nptr++) - '0';
		else
			result += *(nptr++) - '0';
	}
	return (result);
}
