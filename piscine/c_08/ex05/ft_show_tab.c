#include "ft_stock_str.h"
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

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str != 0)
	{
		ft_putstr(par->str);
		ft_putstr("\n");
		ft_putnbr(par->size);
		ft_putstr("\n");
		ft_putstr(par->copy);
		ft_putstr("\n");
		par++;
	}
}
