#include <stdlib.h>

int	is_valid_base(char *base);
int	is_space(char c);

int	get_index_for_base(char c, char *base)
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

int	calculate_number(char *str, char *base, int base_len, int is_negative)
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
		if (is_negative == 1)
			result -= base_idx;
		else
			result += base_idx;
	}
	return (result);
}

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		++length;
	return (length);
}

void	add_digit(char **nbr, char digit)
{
	char	*tmp;
	int		idx;

	tmp = *nbr;
	*nbr = malloc(ft_strlen(*nbr) + 1);
	idx = 0;
	while (tmp[idx])
	{
		(*nbr)[idx] = tmp[idx];
		idx++;
	}
	(*nbr)[idx++] = digit;
	(*nbr)[idx] = '\0';
	free(tmp);
}

void	_putnbr_base(char **converted, unsigned int nbr, char *base)
{
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (nbr >= base_len)
	{
		_putnbr_base(converted, nbr / base_len, base);
	}
	add_digit(converted, base[nbr % base_len]);
}
