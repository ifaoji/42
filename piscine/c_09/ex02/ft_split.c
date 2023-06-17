#include <stdlib.h>
#include <stdio.h>

int	is_separator(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;
	int	in_word;

	in_word = 0;
	count = 0;
	while (*str)
	{
		if (in_word && is_separator(*str, charset))
			in_word = 0;
		if (!in_word && !is_separator(*str, charset))
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

int	get_next_word_len(char **str, char *charset)
{
	int	in_word;
	int	len;

	in_word = 0;
	len = 0;
	while (**str && (*str)[len])
	{
		if (in_word && is_separator((*str)[len], charset))
			break ;
		if (!in_word && !is_separator((*str)[len], charset))
			in_word = 1;
		if (in_word)
			len++;
		else
			(*str)++;
	}
	return (len);
}

char	*next_word(char **str, char *charset)
{
	char	*word;
	int		len;
	int		idx;

	len = get_next_word_len(str, charset);
	word = malloc(len + 1);
	idx = 0;
	while (idx < len)
	{
		word[idx] = (*str)[idx];
		idx++;
	}
	word[idx] = '\0';
	(*str) += len;
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**words;
	int		count;
	int		idx;

	count = count_words(str, charset);
	words = malloc((count + 1) * 8);
	words[count] = 0;
	idx = 0;
	while (idx < count)
	{
		words[idx] = next_word(&str, charset);
		idx++;
	}
	return (words);
}
