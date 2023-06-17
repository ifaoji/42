int	ft_str_is_printable(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] >= 32 && str[idx] <= 126)
		{
			++idx;
			continue ;
		}
		++idx;
		return (0);
	}
	return (1);
}
