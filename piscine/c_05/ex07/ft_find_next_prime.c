int	ft_is_prime(int nb)
{
	int	divisor;

	if (nb <= 1)
		return (0);
	divisor = 2;
	while (divisor <= nb / divisor)
	{
		if (nb % divisor == 0)
			return (0);
		divisor++;
		if (divisor % 2 == 0)
			divisor++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	prime;

	prime = nb;
	while (!ft_is_prime(prime))
		prime++;
	return (prime);
}
