void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	idx;

	idx = 0;
	while (idx < length)
		f(tab[idx++]);
}
