void	ft_sort_int_tab(int *tab, int size)
{
	int	idx;
	int	sort_idx;
	int	tmp;

	if (size <= 1)
		return ;
	idx = 0;
	while (idx < size)
	{
		sort_idx = 0;
		while (sort_idx < size - 1)
		{
			if (tab[sort_idx] > tab[sort_idx + 1])
			{
				tmp = tab[sort_idx + 1];
				tab[sort_idx + 1] = tab[sort_idx];
				tab[sort_idx] = tmp;
				continue ;
			}
			++sort_idx;
		}
		++idx;
	}
}
