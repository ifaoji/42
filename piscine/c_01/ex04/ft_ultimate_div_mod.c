void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div_res;

	div_res = *a / *b;
	*b = *a % *b;
	*a = div_res;
}
