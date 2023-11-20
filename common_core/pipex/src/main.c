/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_init_data(t_data *data, char **argv)
{
	data->name = &argv[0][2];
	data->paths = ft_get_paths();
	if (data->paths == NULL)
		return (perror(data->name), exit(MALLOC_FAILED));
	data->heredoc = false;
	data->pids = NULL;
}

// Pointer to argv array, so we can modify it if heredoc is used
static int	ft_get_start_fd(t_data *data, char **args, char **error)
{
	int		fd;
	int		pipes[2];

	fd = open(args[1], O_RDONLY);
	if (fd < 0)
	{
		*error = strerror(errno);
		if (pipe(pipes) < 0)
			return (ft_perror(data, PIPING_FAILED),
				ft_close(data, -PIPING_FAILED), 0);
		close(pipes[1]);
		fd = pipes[0];
	}
	return (fd);
}

static void	ft_print_usage(char *name)
{
	ft_dprintf(
		STDERR_FILENO,
		"Usage: %s <file1> <cmd1> <cmd2> <file2>\n",
		name
		);
}

static int	ft_save(t_data *data, char *filename, int stdinfd)
{
	char	*error;
	char	buf[1024];
	int		fd;
	int		count;
	int		flags;

	flags = O_TRUNC | O_CREAT | O_WRONLY;
	if (data->heredoc)
		flags = O_CREAT | O_WRONLY | O_APPEND;
	fd = open(filename, flags, 0664);
	if (fd < 0)
	{
		error = strerror(errno);
		ft_dprintf(STDERR_FILENO, "%s: %s: %s\n", data->name, filename, error);
		return (1);
	}
	count = read(stdinfd, buf, 1024);
	while (count > 0)
	{
		write(fd, buf, count);
		count = read(stdinfd, buf, 1024);
	}
	close(fd);
	close(stdinfd);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		status;
	char	*error;
	int		stdinfd;
	int		tmp;

	if (argc != 5)
		return (ft_print_usage(argv[0]), MISSING_ARGS);
	ft_init_data(&data, argv);
	error = NULL;
	stdinfd = ft_get_start_fd(&data, argv, &error);
	if (data.heredoc)
		status = ft_process_cmds(&data, argc - 4, &argv[3], &stdinfd);
	else
		status = ft_process_cmds(&data, argc - 3, &argv[2], &stdinfd);
	tmp = ft_save(&data, argc[argv - 1], stdinfd);
	if (tmp > 0)
		status = tmp;
	if (error != NULL)
	{
		ft_dprintf(STDERR_FILENO, "%s: %s: %s\n", data.name, argv[1], error);
		status = 0;
	}
	ft_close(&data, status);
}
