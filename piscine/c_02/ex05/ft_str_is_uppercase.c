int	ft_str_is_uppercase(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] >= 'A' && str[idx] <= 'Z')
		{
			++idx;
			continue ;
		}
		++idx;
		return (0);
	}
	return (1);
}
