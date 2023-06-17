#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		++length;
	return (length);
}

int	is_valid_base(char *base)
{
	int		base_idx;
	int		count;
	int		check_idx;

	base_idx = 0;
	while (base[base_idx])
	{
		if (base[base_idx] == '+' || base[base_idx] == '-')
			return (0);
		count = 0;
		check_idx = 0;
		while (base[check_idx])
		{
			if (base[check_idx] == base[base_idx])
				count += 1;
			check_idx += 1;
		}
		if (count > 1)
			return (0);
		base_idx += 1;
	}
	if (base_idx <= 1)
		return (0);
	return (1);
}

void	_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (nbr >= base_len)
	{
		_putnbr_base(nbr / base_len, base);
	}
	write(1, &base[nbr % base_len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	positive_nbr;

	if (is_valid_base(base) == 0)
		return ;
	positive_nbr = nbr;
	if (nbr < 0)
	{
		write(1, "-", 1);
		positive_nbr = nbr * -1;
	}
	_putnbr_base(positive_nbr, base);
}
