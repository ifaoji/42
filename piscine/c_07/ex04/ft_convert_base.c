#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
int		calculate_number(char *str, char *base, int base_len, int is_negative);
void	add_digit(char **nbr, char digit);
void	_putnbr_base(char **converted, unsigned int nbr, char *base);

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

int	is_valid_base(char *base)
{
	int		base_idx;
	int		count;
	char	*check;

	base_idx = 0;
	while (base[base_idx])
	{
		if (base[base_idx] == '+'
			|| base[base_idx] == '-'
			|| is_space(base[base_idx]))
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

char	*ft_cnvnbr_base(int nbr, char *base)
{
	unsigned int	positive_nbr;
	char			*converted;

	converted = malloc(1);
	positive_nbr = nbr;
	if (nbr < 0)
	{
		add_digit(&converted, '-');
		positive_nbr = nbr * -1;
	}
	_putnbr_base(&converted, positive_nbr, base);
	return (converted);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	is_negative;

	base_len = is_valid_base(base);
	if (base_len == 0)
		return (0);
	is_negative = 0;
	while (*str && is_space(*str))
		str += 1;
	while (*str && (*str == '-' || *str == '+'))
	{
		if (*(str++) != '-')
			continue ;
		if (is_negative == 1)
			is_negative = 0;
		else
			is_negative = 1;
	}
	return (calculate_number(str, base, base_len, is_negative));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	parsed;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (NULL);
	parsed = ft_atoi_base(nbr, base_from);
	return (ft_cnvnbr_base(parsed, base_to));
}
