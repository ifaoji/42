/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This atoi handles overflows and invalid characters in the provided string.
 * If an illegal character is encounterd, then it returns 0.
 * It should be checked, whether the string contains only a '0',
 * when a 0 gets returned.
 */
static int	ft_protective_atoi(char *nptr)
{
	bool	is_negative;
	int		result;

	while (*nptr && (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r')))
		++nptr;
	is_negative = false;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			is_negative = true;
	result = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (result > INT_MAX / 10
			|| (!is_negative && result == INT_MAX / 10 && *nptr - '0' > 7)
			|| (is_negative && result == INT_MAX / 10 && *nptr - '0' > 8))
			break ;
		result = result * 10 + *(nptr++) - '0';
	}
	if (is_negative)
		result *= -1;
	if (*nptr != '\0')
		result = 0;
	return (result);
}

static bool	ft_contains_int(int *haystack, int needle, int amount)
{
	int	idx;

	idx = 0;
	while (idx < amount)
	{
		if (haystack[idx] == needle)
			return (true);
		idx++;
	}
	return (false);
}

/** Parse `count` ascii strings to an integer array.
 *  Returns `NULL` if the malloc fails,
 *  any of the ascii strings contains an illegal character,
 *  or when the array contains duplicated ints.
 */
static int	*ft_parse_unique_ints(int count, char **raw)
{
	int	*ints;
	int	idx;

	ints = malloc(count * sizeof(int *));
	if (ints == NULL)
		return (NULL);
	idx = 0;
	while (idx < count)
	{
		ints[idx] = ft_protective_atoi(raw[idx]);
		if (
			ft_contains_int(ints, ints[idx], idx)
			|| (ints[idx] == 0 && (raw[idx][0] != '0' || raw[idx][1] != '\0'))
		)
			return (free(ints), NULL);
		idx++;
	}
	return (ints);
}

/** Parse all values of argv to an integer and store them in `dest`.
 *  @return amount of integers in `dest`.
 *
 *  Panics:
 *   - If malloc fails.
 *   - If a argument is not a valid int.
 *   - Duplicate ints.
 */
int	ft_parse_args(int **dest, int argc, char **argv)
{
	char	**splitted;
	int		amount;

	if (argc == 1)
		exit(0);
	if (argc == 2)
	{
		splitted = ft_split(argv[1], ' ');
		if (splitted == NULL)
			ft_panic(MALLOC_FAILED);
		amount = 0;
		while (splitted[amount])
			amount++;
		*dest = ft_parse_unique_ints(amount, splitted);
		ft_free_matrix((void **) splitted, free);
	}
	else
	{
		amount = argc - 1;
		*dest = ft_parse_unique_ints(amount, &argv[1]);
	}
	if (*dest == NULL)
		ft_panic(PARSING_ARGS);
	return (amount);
}
