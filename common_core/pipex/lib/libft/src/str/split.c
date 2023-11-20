/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_substrs(char const *s, char c)
{
	size_t	count;
	bool	in_word;

	count = 0;
	in_word = false;
	while (*s)
	{
		if (!in_word && *s != c)
		{
			++count;
			in_word = true;
		}
		else if (in_word && *s == c)
			in_word = false;
		++s;
	}
	return (count);
}

static size_t	ft_next_word_len(char const *s, char c)
{
	const char	*t;

	t = s;
	while (*t && *t != c)
		t++;
	return (t - s);
}

static char	*ft_extract_word(char const **s, char c)
{
	const char	*r;
	char		*word;
	char		*tmp;
	size_t		len;

	r = *s;
	len = ft_next_word_len(r, c);
	word = malloc(len + 1);
	if (word == NULL)
		return (NULL);
	word[len] = '\0';
	tmp = word;
	while (*r && len-- > 0)
		*tmp++ = *r++;
	*s = r;
	return (word);
}

static void	ft_free_all(char **split)
{
	size_t	idx;

	if (split == NULL)
		return ;
	idx = 0;
	while (split[idx] != NULL)
		free(split[idx++]);
	free(split);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**splitted;

	if (s == NULL)
		return (NULL);
	count = ft_count_substrs(s, c);
	splitted = malloc((count + 1) * sizeof(char *));
	if (splitted == NULL)
		return (NULL);
	splitted[count] = NULL;
	count = 0;
	while (*s)
	{
		if (*s == c)
		{
			s++;
			continue ;
		}
		splitted[count] = ft_extract_word(&s, c);
		if (splitted[count] == NULL)
			return (ft_free_all(splitted), NULL);
		count++;
	}
	return (splitted);
}
