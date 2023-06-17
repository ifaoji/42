#include "ft_hexdump.h"

void	*falloc(unsigned long bytes)
{
	unsigned char	*blob;

	blob = malloc(bytes);
	if (blob == NULL)
		return (NULL);
	while (1)
	{
		blob[--bytes] = 0;
		if (bytes == 0)
			break ;
	}
	return (blob);
}
