int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	idx;

	idx = 0;
	while (idx < n && !(s1[idx] == '\0' && s2[idx] == '\0'))
	{
		if (s1[idx] != s2[idx])
			return (s1[idx] - s2[idx]);
		++idx;
	}
	return (0);
}
