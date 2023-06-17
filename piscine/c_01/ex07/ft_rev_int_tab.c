void	ft_rev_int_tab(int *tab, int size)
{
	int	tmp;
	int	idx;

	idx = 0;
	while (idx < size / 2)
	{
		tmp = tab[idx];
		tab[idx] = tab[size - idx - 1];
		tab[size - idx - 1] = tmp;
		++idx;
	}
}
