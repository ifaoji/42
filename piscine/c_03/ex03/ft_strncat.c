int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		++length;
	return (length);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	dest_len;
	unsigned int	idx;

	dest_len = ft_strlen(dest);
	idx = 0;
	while (src[idx] && idx < nb)
	{
		dest[dest_len + idx] = src[idx];
		++idx;
	}
	dest[dest_len + idx] = '\0';
	return (dest);
}
