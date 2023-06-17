#include <unistd.h>
#include <stdbool.h>

void	ft_print_comb(void)
{
	char	numbers[3];

	numbers[0] = '0';
	numbers[1] = '1';
	numbers[2] = '2';
	while (true)
	{
		write(1, &numbers, 3);
		if (++numbers[2] > '9')
		{
			numbers[2] = numbers[1] + 2;
			if (++numbers[1] > '8')
			{
				if (++numbers[0] > '7')
					break ;
				numbers[1] = numbers[0] + 1;
				numbers[2] = numbers[0] + 2;
			}
		}
		write(1, ", ", 2);
	}
}
