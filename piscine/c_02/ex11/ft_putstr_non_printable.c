#include <unistd.h>
#include <stdio.h>

int	is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

char	to_hex(char c)
{
	if (c >= 0 && c <= 9)
		return ('0' + c);
	else
		return (c + 'a' - 10);
}

void	print_hex(int c, int min_length)
{
	if (c < 0)
		c = 256 + c;
	if (c / 16 > 0)
		print_hex(c / 16, min_length - 1);
	else
	{
		while (--min_length > 0)
			write(1, "0", 1);
	}
	c %= 16;
	if (c >= 0 && c <= 9)
		c += '0';
	else
		c += 'a' - 10;
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (is_printable(str[idx]))
		{
			write(1, &str[idx], 1);
		}
		else
		{
			write(1, "\\", 1);
			print_hex(str[idx], 2);
		}
		++idx;
	}
}
