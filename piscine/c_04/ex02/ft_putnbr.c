#include <unistd.h>

void	ft_putnbr(int nb)
{
	unsigned int	divider;
	unsigned int	num;
	char			temporary;

	divider = 1000000000;
	num = nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		num = -nb;
	}
	while (divider > num && divider != 1)
		divider /= 10;
	while (1)
	{
		temporary = '0' + (num / divider);
		num = num % divider;
		write(1, &temporary, 1);
		if (divider == 1)
			break ;
		divider /= 10;
	}
}
