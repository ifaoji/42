int	ft_str_is_lowercase(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] >= 'a' && str[idx] <= 'z')
		{
			++idx;
			continue ;
		}
		++idx;
		return (0);
	}
	return (1);
}
