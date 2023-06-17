int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	count;
	int	idx;

	count = 0;
	idx = 0;
	while (idx < length)
	{
		if (f(tab[idx]) != 0)
			count++;
		idx++;
	}
	return (count);
}
