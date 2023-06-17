int	is_word_char(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	idx;
	int	in_word;

	idx = 0;
	in_word = 0;
	while (str[idx] != '\0')
	{
		if (in_word && is_word_char(str[idx]))
		{
			if (str[idx] >= 'A' && str[idx] <= 'Z')
				str[idx] += 32;
		}
		else if (in_word)
			in_word = 0;
		else if (!in_word && is_word_char(str[idx]))
		{
			in_word = 1;
			if (str[idx] >= 'a' && str[idx] <= 'z')
				str[idx] -= 32;
		}
		++idx;
	}
	return (str);
}
