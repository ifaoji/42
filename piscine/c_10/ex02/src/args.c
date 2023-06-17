#include "ft_tail.h"

int	simple_atoi(char *str)
{
	int	result;

	result = 0;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (-1);
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result);
}

void	ft_puterroptionarg(char *name)
{
	ft_puterrstr(basename(name));
	ft_puterrstr(": option requires an argument -- 'c'\nTry '");
	ft_puterrstr(basename(name));
	ft_puterrstr(" --help' for more information.\n");
}

void	ft_puterroptioninvalid(char *name, char *option)
{
	ft_puterrstr(basename(name));
	ft_puterrstr(": invalid number of bytes: ‘");
	ft_puterrstr(option);
	ft_puterrstr("’\n");
}

int	get_bytes(int argc, char **argv)
{
	int	idx;
	int	result;

	idx = 1;
	while (idx < argc)
	{
		if (ft_strcmp(argv[idx++], "-c") != 0)
			continue ;
		if (idx >= argc)
		{
			ft_puterroptionarg(argv[0]);
			return (-1);
		}
		result = simple_atoi(argv[idx]);
		if (result == -1)
		{
			ft_puterroptioninvalid(argv[0], argv[idx]);
			return (-1);
		}
		return (result);
	}
	return (INT_MAX);
}

int	real_arg_count(int argc, char **argv)
{
	int	count;
	int	idx;

	count = 0;
	idx = 1;
	while (idx < argc)
	{
		if (ft_strcmp(argv[idx], "-c") == 0)
		{
			idx += 2;
			continue ;
		}
		count++;
		idx++;
	}
	return (count);
}
