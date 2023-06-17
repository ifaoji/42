int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

// int	ft_fibonacci(int index)
// {
// 	int	current;
// 	int	next;
// 	int	tmp;

// 	if (index < 0)
// 		return (-1);
// 	current = 0;
// 	next = 1;
// 	while (index-- > 0)
// 	{
// 		tmp = current;
// 		current = next;
// 		next = tmp + next;
// 	}
// 	return (current);
// }
