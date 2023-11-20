/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// If the base is valid returns the length. If not 0.
static int	is_valid_base(char *base)
{
	int		base_idx;
	int		count;
	char	*check;

	base_idx = 0;
	while (base[base_idx])
	{
		if (base[base_idx] == '+'
			|| base[base_idx] == '-'
			|| ft_isspace(base[base_idx]))
			return (0);
		count = 0;
		check = base;
		while (*check)
		{
			if (*(check++) == base[base_idx])
				count += 1;
			if (count > 1)
				return (0);
		}
		base_idx += 1;
	}
	if (base_idx <= 1)
		return (0);
	return (base_idx);
}

// Returns `-1` if the char was not found.
static int	get_index_for_base(char c, char *base)
{
	int	idx;

	idx = 0;
	while (base[idx])
	{
		if (c == base[idx])
			return (idx);
		idx += 1;
	}
	return (-1);
}

static int	calculate_number(char *str, char *base,
	int base_len, bool is_negative)
{
	int	base_idx;
	int	result;

	result = 0;
	while (*str)
	{
		base_idx = get_index_for_base(*(str++), base);
		if (base_idx == -1)
			break ;
		result *= base_len;
		result += base_idx;
	}
	if (is_negative)
		return (result * -1);
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int		base_len;
	bool	is_negative;

	base_len = is_valid_base(base);
	if (base_len == 0)
		return (0);
	while (*str && ft_isspace(*str))
		str += 1;
	is_negative = false;
	if ((*str == '+' || *str == '-') && *str++ == '-')
		is_negative = true;
	return (calculate_number(str, base, base_len, is_negative));
}
