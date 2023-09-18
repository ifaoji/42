/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_params	ft_create_params(va_list *args)
{
	t_params	params;

	params.args = args;
	params.len = 0;
	params.min_width = 0;
	params.precision = -1;
	params.flags = 0;
	params.type = 0;
	return (params);
}

void	ft_parse_params_flags(const char *str, size_t *len, t_params *params)
{
	while (ft_strchr("+- #0", str[*len]))
	{
		if (str[*len] == '+')
			params->flags |= PLUS;
		if (str[*len] == '-')
			params->flags |= JUSTIFY_LEFT;
		if (str[*len] == ' ')
			params->flags |= SPACE;
		if (str[*len] == '#')
			params->flags |= HEX_PREFIX;
		if (str[*len] == '0')
			params->flags |= ZERO_PAD;
		*len += 1;
	}
}

enum e_type	ft_parse_type(t_params *params, char type)
{
	if (type == 'c')
		return (CHARACTER);
	if (type == 's')
		return (STRING);
	if (type == 'p')
		return (POINTER);
	if (type == 'd' || type == 'i')
		return (INTEGER);
	if (type == 'u')
		return (UNSIGNED_INTEGER);
	if (type == 'x')
		return (HEXADECIMAL);
	if (type == 'X')
	{
		params->flags |= BIG_HEX;
		return (HEXADECIMAL);
	}
	return (PERCENT);
}

int	ft_parse_dot(t_params *params, const char *str)
{
	int	result;

	params->precision = 0;
	if (ft_strrchr("0123456789", *str))
	{
		result = 0;
		while (ft_strrchr("0123456789", *str))
		{
			params->precision *= 10;
			params->precision += *str - '0';
			str++;
			result++;
		}
		return (result);
	}
	return (0);
}

t_params	ft_parse_params(const char *str, va_list *args)
{
	size_t		len;
	t_params	params;

	params = ft_create_params(args);
	len = 1;
	ft_parse_params_flags(str, &len, &params);
	if (ft_strrchr("0123456789", str[len]))
	{
		params.min_width = ft_atoi(&str[len]);
		len += ft_calculate_width(params.min_width);
	}
	if (str[len] == '.')
	{
		len += 1;
		len += ft_parse_dot(&params, &str[len]);
	}
	if (ft_strchr("cspdiuxX%", str[len]) != NULL)
	{
		params.type = ft_parse_type(&params, str[len]);
		params.len = len + 1;
		return (params);
	}
	params.type = PERCENT;
	params.len = len;
	return (params);
}
