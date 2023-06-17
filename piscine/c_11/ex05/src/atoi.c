int	is_space(char c)
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

int	ft_atoi(char *str)
{
	int	is_negative;
	int	result;

	while (*str && is_space(*str))
		str += 1;
	is_negative = 0;
	while (*str && (*str == '-' || *str == '+'))
	{
		if (*(str++) != '-')
			continue ;
		if (is_negative == 1)
			is_negative = 0;
		else
			is_negative = 1;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		if (is_negative == 1)
			result -= *(str++) - '0';
		else
			result += *(str++) - '0';
	}
	return (result);
}
