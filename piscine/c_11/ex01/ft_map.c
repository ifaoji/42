#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	idx;
	int	*res;

	res = malloc(length * sizeof(int));
	idx = 0;
	while (idx < length)
	{
		res[idx] = f(tab[idx]);
		idx++;
	}
	return (res);
}
