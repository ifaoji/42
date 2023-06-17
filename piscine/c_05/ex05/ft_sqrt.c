int	ft_sqrt(int nb)
{
	int	factor;

	if (nb <= 0 || nb > 2147395600)
		return (0);
	factor = 0;
	while (factor * factor <= nb)
	{
		if (factor * factor == nb)
			return (factor);
		factor++;
	}
	return (0);
}
