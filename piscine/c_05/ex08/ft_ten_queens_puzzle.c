#include <unistd.h>

void	putsolution(int grid[][10])
{
	int	idx;
	int	jdx;

	idx = 0;
	while (idx < 10)
	{
		jdx = 0;
		while (jdx < 10)
		{
			if (grid[idx][jdx])
				write(1, &"0123456789"[jdx], 1);
			jdx++;
		}
		idx++;
	}
	write(1, "\n", 1);
}

int	check_queen(int grid[][10], int queen, int y)
{
	int	idx;
	int	spread;

	spread = 0;
	idx = queen;
	while (idx++ < 10)
	{
		if (grid[idx - 1][y] || (y + spread <= 9 && grid[idx - 1][y + spread]))
			return (0);
		if (y - spread >= 0 && grid[idx - 1][y - spread])
			return (0);
		spread++;
	}
	spread = 0;
	idx = queen;
	while (idx-- >= 0)
	{
		if (grid[idx + 1][y] || (y + spread <= 9 && grid[idx + 1][y + spread]))
			return (0);
		if (y - spread >= 0 && grid[idx + 1][y - spread])
			return (0);
		spread++;
	}
	return (1);
}

int	spawn(int grid[][10], int queen)
{
	int	count;
	int	idx;

	count = 0;
	idx = 0;
	while (idx < 10)
	{
		if (!check_queen(grid, queen, idx))
		{
			idx++;
			continue ;
		}
		grid[queen][idx] = 1;
		if (queen == 9)
		{
			putsolution(grid);
			count++;
		}
		if (queen < 9)
			count += spawn(grid, queen + 1);
		grid[queen][idx] = 0;
		idx++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int	grid[10][10];
	int	idx;
	int	jdx;

	idx = 0;
	while (idx < 10)
	{
		jdx = 0;
		while (jdx < 10)
		{
			grid[idx][jdx] = 0;
			jdx++;
		}
		idx++;
	}
	return (spawn(grid, 0));
}
