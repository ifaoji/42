#include <unistd.h>

void	print_data(char c)
{
	if (c >= 32 && c <= 126)
	{
		write(1, &c, 1);
		return ;
	}
	write(1, ".", 1);
}

void	print_hex(unsigned long long int c, int min_length)
{
	if (c / 16 > 0)
		print_hex(c / 16, min_length - 1);
	else
	{
		while (--min_length > 0)
			write(1, "0", 1);
	}
	c %= 16;
	if (c <= 9)
		c += '0';
	else
		c += 'a' - 10;
	write(1, &c, 1);
}

void	print_line(void *addr, unsigned int offset, unsigned int size)
{
	unsigned int	idx;

	print_hex((unsigned long long int)(((int *) addr)) + offset, 16);
	write(1, ": ", 2);
	idx = 0;
	while (idx < 16)
	{
		if ((offset + idx) < size)
			print_hex(
				(unsigned long long int)
				((unsigned char *)addr)[offset + idx],
				2);
		else
			write(1, "  ", 2);
		if (idx % 2 == 1)
			print_data(' ');
		++idx;
	}
	idx = 0;
	while (idx < 16 && (offset + idx) < size)
		print_data(
			(unsigned long long int)
			((unsigned char *)addr)[offset + idx++]
			);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	idx;

	idx = 0;
	while (idx < (size / 16 + (size % 16 > 0)))
	{
		print_line(addr, idx * 16, size);
		write(1, "\n", 1);
		++idx;
	}
	return (addr);
}
