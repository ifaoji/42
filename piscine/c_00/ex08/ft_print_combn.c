#include <unistd.h>

int	checked_increase(char numbers[], int len, int idx)
{
	char	max;

	if (idx < 0)
		return (0);
	max = '0' + 9 - (len - 1 - idx);
	if (++numbers[idx] > max)
	{
		numbers[idx] = '0';
		return (checked_increase(numbers, len, idx - 1));
	}
	if (idx != (len - 1))
	{
		if (numbers[idx] > numbers[idx + 1])
		{
			++idx;
			while (idx < len)
			{
				numbers[idx] = numbers[idx - 1] + 1;
				++idx;
			}
		}
	}
	return (1);
}

void	ft_print_combn(int n)
{
	char	numbers[10];
	int		length;

	length = n;
	numbers[n] = '\0';
	while (n-- != 0)
		numbers[n] = '0' + n;
	while (1)
	{
		write(1, &numbers, length);
		if (!checked_increase(numbers, length, length - 1))
		{
			break ;
		}
		write(1, ", ", 2);
	}
}
