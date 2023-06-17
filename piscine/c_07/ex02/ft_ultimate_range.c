#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	idx;
	int	size;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = 0;
	idx = min;
	while (idx++ < max)
		size++;
	*range = malloc(size * 4);
	if (*range == NULL)
		return (-1);
	idx = 0;
	while (min < max)
	{
		(*range)[idx] = min;
		min++;
		idx++;
	}
	return (size);
}
