#include "do_op.h"

void	_puterr(char *str)
{
	while (*str)
		write(STDERR_FILENO, str++, 1);
}

void	ft_puterr(t_error error)
{
	if (error == DIV_ZERO)
		_puterr("Stop : division by zero\n");
	if (error == MOD_ZERO)
		_puterr("Stop : modulo by zero\n");
}

void	ft_putstr(char *str)
{
	while (*str)
		write(STDOUT_FILENO, str++, 1);
}

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
