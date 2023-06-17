#include <unistd.h>
#include <stdbool.h>

void	print_int(int n)
{
	char	first;
	char	second;

	second = '0' + n % 10;
	first = '0' + n / 10;
	write(1, &first, 1);
	write(1, &second, 1);
}

void	ft_print_comb2(void)
{
	int	first;
	int	second;

	first = 0;
	second = 1;
	while (true)
	{
		while (second < 100)
		{
			print_int(first);
			write(1, " ", 1);
			print_int(second);
			if (!(first == 98 && second == 99))
				write(2, ", ", 2);
			++second;
		}
		++first;
		second = first + 1;
		if (first == 99)
			break ;
	}
}
