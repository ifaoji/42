unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;
	int				length;

	length = 0;
	while (src[length] != '\0')
		++length;
	if (size == 0)
		return (length);
	idx = 0;
	while (idx < (size - 1) && src[idx] != '\0')
	{
		dest[idx] = src[idx];
		++idx;
	}
	dest[idx] = '\0';
	return (length);
}
