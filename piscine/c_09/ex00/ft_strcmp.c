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
