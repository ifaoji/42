int	ft_str_is_numeric(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] >= '0' && str[idx] <= '9')
		{
			++idx;
			continue ;
		}
		++idx;
		return (0);
	}
	return (1);
}
