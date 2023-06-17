int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		++length;
	return (length);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	space_left;
	char			*tmp;
	int				dest_len;
	int				idx;

	space_left = size;
	tmp = dest;
	while (*tmp && space_left > 0)
	{
		tmp++;
		space_left--;
	}
	if (space_left == 0)
		return (tmp - dest + ft_strlen(src));
	dest_len = tmp - dest;
	idx = 0;
	while (space_left > 1 && src[idx])
	{
		dest[dest_len + idx] = src[idx];
		idx++;
		space_left--;
	}
	dest[dest_len + idx] = '\0';
	return (dest_len + ft_strlen(src));
}
