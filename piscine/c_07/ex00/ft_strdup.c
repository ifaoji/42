#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*cpy;
	int		idx;

	cpy = malloc(ft_strlen(src));
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
