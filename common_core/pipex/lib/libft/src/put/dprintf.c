/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_dprintf_p(void *ptr, int fd)
{
	uintptr_t	uptr;
	int			written;

	if (ptr == NULL)
		return (ft_putstr_fd("(nil)", fd));
	uptr = (uintptr_t) ptr;
	written = ft_putstr_fd("0x", fd);
	written += ft_putbase_fd(uptr, "0123456789abcdef", fd);
	return (written);
}

static int	ft_print_param(int fd, const char format, va_list *args)
{
	char	*str;

	if (format == 'c')
		return (ft_putchar_fd(va_arg(*args, int), fd));
	if (format == 's')
	{
		str = va_arg(*args, char *);
		if (str == NULL)
			return (ft_putstr_fd("(null)", fd));
		return (ft_putstr_fd(str, fd));
	}
	if (format == 'p')
		return (ft_dprintf_p(va_arg(*args, char *), fd));
	if (format == 'x')
		return (ft_putbase_fd(va_arg(*args, unsigned int),
				"0123456789abcdef", fd));
	if (format == 'X')
		return (ft_putbase_fd(va_arg(*args, unsigned int),
				"0123456789ABCDEF", fd));
	if (format == 'i' || format == 'd')
		return (ft_putnbr_fd(va_arg(*args, int), fd));
	if (format == 'u')
		return (ft_putunbr_fd(va_arg(*args, unsigned int), fd));
	return (ft_putchar_fd(fd, format));
}

static int	ft_dprintf_internal(int fd, const char *format, va_list *args)
{
	int		chars_printed;

	if (format == NULL)
		return (-1);
	chars_printed = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);
			chars_printed += ft_print_param(fd, *format, args);
			format++;
			continue ;
		}
		chars_printed += write(fd, format, 1);
		format++;
	}
	return (chars_printed);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		chars_printed;

	va_start(args, format);
	chars_printed = ft_dprintf_internal(fd, format, &args);
	va_end(args);
	return (chars_printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		chars_printed;

	va_start(args, format);
	chars_printed = ft_dprintf_internal(STDOUT_FILENO, format, &args);
	va_end(args);
	return (chars_printed);
}
