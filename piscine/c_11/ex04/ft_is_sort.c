int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	idx;
	int	ascending;

	if (length < 2)
		return (1);
	idx = 0;
	ascending = -1;
	while (idx < length - 1)
	{
		if (ascending == -1 && f(tab[idx], tab[idx + 1]) != 0)
			ascending = f(tab[idx], tab[idx + 1]) > 0;
		if (ascending == 1 && f(tab[idx], tab[idx + 1]) < 0)
			return (0);
		if (ascending == 0 && f(tab[idx], tab[idx + 1]) > 0)
			return (0);
		idx++;
	}
	return (1);
}
