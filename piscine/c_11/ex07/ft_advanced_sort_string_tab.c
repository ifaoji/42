#include <unistd.h>

int	ft_tablen(char **tab)
{
	int	idx;

	idx = 0;
	while (tab[idx] != NULL)
		idx++;
	return (idx);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		idx;
	int		sort_idx;
	char	*tmp;
	int		size;

	size = ft_tablen(tab);
	idx = 0;
	while (idx < size)
	{
		sort_idx = 0;
		while (sort_idx < size - 1)
		{
			if (cmp(tab[sort_idx], tab[sort_idx + 1]) > 0)
			{
				tmp = tab[sort_idx + 1];
				tab[sort_idx + 1] = tab[sort_idx];
				tab[sort_idx] = tmp;
			}
			sort_idx += 1;
		}
		idx += 1;
	}
}
