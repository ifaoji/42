/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int *total, t_params params, char c)
{
	ft_print_min_width(total, params, true, 1);
	*total += 1;
	write(STDOUT_FILENO, &c, 1);
	ft_print_min_width(total, params, false, 1);
}

void	ft_putstr(int *total, t_params params, char *str)
{
	size_t	len;

	if (str == NULL)
	{
		len = 6;
		if (params.precision >= 0 && params.precision < 6)
			len = 0;
	}
	else
	{
		len = ft_strlen(str);
		if (params.precision >= 0 && (size_t) params.precision < len)
			len = params.precision;
	}
	ft_print_min_width(total, params, true, len);
	if (str == NULL && len == 6)
		ft_putstr_count(total, "(null)");
	else if (len != 0)
	{
		*total += len;
		write(STDOUT_FILENO, str, len);
	}
	ft_print_min_width(total, params, false, len);
}

void	ft_printf_string(int *total, t_params params, char *str)
{
	size_t	len;

	if (str == NULL)
		return (ft_printf_string(total, params, "(null)"));
	len = ft_strlen(str);
	if (len == 0)
		return ;
	if (params.precision >= 0 && (size_t) params.precision < len)
		len = params.precision;
	*total += len;
	write(STDOUT_FILENO, str, len);
}

void	ft_putchar_count(int *total, char c)
{
	write(STDOUT_FILENO, &c, 1);
	*total += 1;
}

void	ft_putstr_count(int *total, char *str)
{
	size_t	len;

	if (str == NULL)
	{
		write(STDOUT_FILENO, "(null)", 6);
		(*total) += 6;
		return ;
	}
	len = ft_strlen(str);
	write(STDOUT_FILENO, str, len);
	*total += len;
}
