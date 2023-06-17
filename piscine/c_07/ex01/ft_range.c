#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	idx;
	int	size;

	if (min >= max)
		return (NULL);
	size = 0;
	idx = min;
	while (idx++ < max)
		size++;
	arr = malloc(size * 4);
	if (arr == NULL)
		return (NULL);
	idx = 0;
	while (min < max)
	{
		arr[idx] = min;
		min++;
		idx++;
	}
	return (arr);
}
