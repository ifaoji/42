char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	idx;

	idx = 0;
	while (idx < n && src[idx] != '\0')
	{
		dest[idx] = src[idx];
		++idx;
	}
	while (idx < n)
	{
		dest[idx] = '\0';
		++idx;
	}
	return (dest);
}
