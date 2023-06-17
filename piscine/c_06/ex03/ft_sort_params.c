#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

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

void	sort_str_tab(char **tab, int size)
{
	int		idx;
	int		sort_idx;
	int		compare_result;
	char	*tmp;

	idx = 0;
	while (idx < size)
	{
		sort_idx = 0;
		while (sort_idx < size - 1)
		{
			compare_result = ft_strcmp(tab[sort_idx], tab[sort_idx + 1]);
			if (compare_result > 0)
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

int	main(int argc, char **argv)
{
	char	*programm_name;
	int		idx;

	if (argc == 1)
		return (0);
	programm_name = argv[0];
	sort_str_tab(argv, argc);
	idx = 0;
	while (idx < argc)
	{
		if (argv[idx] == programm_name)
		{
			idx += 1;
			continue ;
		}
		ft_putstr(argv[idx++]);
		ft_putstr("\n");
	}
	return (0);
}
