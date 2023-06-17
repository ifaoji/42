#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		++length;
	return (length);
}

char	*ft_strcat(char *dest, char *src)
{
	int	dest_idx;
	int	src_idx;

	dest_idx = ft_strlen(dest);
	src_idx = 0;
	while (src[src_idx] != '\0')
		dest[dest_idx++] = src[src_idx++];
	dest[dest_idx] = '\0';
	return (dest);
}

char	*falloc(int size)
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

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		idx;
	int		strs_len;

	if (size == 0)
		return (falloc(1));
	idx = 0;
	strs_len = 0;
	while (idx < size)
		strs_len += ft_strlen(strs[idx++]);
	str = falloc(strs_len + ft_strlen(sep) * (size - 1) + 1);
	if (str == NULL)
		return (NULL);
	idx = 0;
	while (idx < size)
	{
		ft_strcat(str, strs[idx]);
		if (++idx < size)
			ft_strcat(str, sep);
	}
	return (str);
}
