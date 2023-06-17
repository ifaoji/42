#include <unistd.h>

void	ft_putstr(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		++length;
	write(1, str, length);
}
