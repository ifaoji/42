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
