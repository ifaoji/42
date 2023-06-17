int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		++length;
	return (length);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	idx;
	int	find_idx;
	int	find_length;

	find_length = ft_strlen(to_find);
	if (find_length == 0)
		return (str);
	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] == *to_find)
		{
			find_idx = 0;
			while (str[idx + find_idx] == to_find[find_idx]
				&& str[idx + find_idx])
				++find_idx;
			if (find_idx == find_length)
				return (&str[idx]);
		}
		++idx;
	}
	return (0);
}
