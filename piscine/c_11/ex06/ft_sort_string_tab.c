#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while (!(s1[idx] == '\0' && s2[idx] == '\0'))
	{
		if (s1[idx] == s2[idx])
		{
			++idx;
			continue ;
		}
		return (s1[idx] - s2[idx]);
	}
	return (0);
}

int	ft_tablen(char **tab)
{
	int	idx;

	idx = 0;
	while (tab[idx] != NULL)
		idx++;
	return (idx);
}

void	ft_sort_string_tab(char **tab)
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
			if (ft_strcmp(tab[sort_idx], tab[sort_idx + 1]) > 0)
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
