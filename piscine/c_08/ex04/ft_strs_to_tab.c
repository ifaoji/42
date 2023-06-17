#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	*falloc(int size)
{
	char	*stupid;
	int		idx;

	stupid = malloc(size);
	if (stupid == NULL)
		return (NULL);
	idx = 0;
	while (idx < size)
		stupid[idx++] = 0;
	return (stupid);
}

char	*ft_strdup(char *src)
{
	char	*cpy;
	int		idx;

	cpy = falloc(ft_strlen(src) + 1);
	if (cpy == NULL)
		return (NULL);
	idx = 0;
	while (src[idx])
	{
		cpy[idx] = src[idx];
		idx += 1;
	}
	cpy[idx] = '\0';
	return (cpy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					idx;
	struct s_stock_str	*stocks;

	stocks = falloc((ac + 1) * 24);
	if (stocks == NULL)
		return (NULL);
	idx = 0;
	while (idx < ac)
	{
		stocks[idx].size = ft_strlen(av[idx]);
		stocks[idx].str = av[idx];
		stocks[idx].copy = ft_strdup(av[idx]);
		idx++;
	}
	stocks[idx].str = 0;
	return (stocks);
}
