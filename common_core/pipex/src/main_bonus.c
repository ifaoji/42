/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
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

static int	ft_heredoc(t_data *data, int pipes[2], char *limiter)
{
	char	*line;
	int		len;
	int		res;
	int		line_count;

	len = ft_strlen(limiter);
	res = ft_gnl(STDIN_FILENO, &line);
	line_count = 1;
	while (res == 1 && line != NULL && line_count++)
	{
		if (ft_strncmp(line, limiter, len) == 0 && line[len] == '\n')
			return (free(line), ft_gnl_clear_cache(), close(pipes[1]));
		write(pipes[1], line, ft_strlen(line));
		free(line);
		ft_printf("> ");
		res = ft_gnl(STDIN_FILENO, &line);
	}
	ft_gnl_clear_cache();
	if (res < 0)
		return (perror("Error"), ft_close(data, READ_ERROR), 0);
	if (line == NULL)
		ft_dprintf(STDERR_FILENO,
			"\n%s: warning: here-document at line %i %s (wanted `%s')\n",
			data->name, line_count, "delimited by end-of-file", limiter);
	return (close(pipes[1]));
}

// Pointer to argv array, so we can modify it if heredoc is used
static int	ft_get_start_fd(t_data *data, char **args, char **error)
{
	int		fd;
	int		pipes[2];

	if (ft_strncmp(args[1], "here_doc", 9) == 0)
	{
		data->heredoc = true;
		pipe(pipes);
		ft_printf("> ");
		ft_heredoc(data, pipes, args[2]);
		return (pipes[0]);
	}
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

int	ft_save(t_data *data, char *filename, int stdinfd)
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

	if (argc < 5)
		return (ft_dprintf(
				STDERR_FILENO, "Usage: %s [here_doc <limiter>] %s\n",
				argv[0], "<file1> <cmd1> <cmd2> [cmds] <file2>"
			), MISSING_ARGS);
	ft_init_data(&data, argv);
	error = NULL;
	stdinfd = ft_get_start_fd(&data, argv, &error);
	if (data.heredoc)
		status = ft_process_cmds(&data, argc - 4, &argv[3], &stdinfd);
	else
		status = ft_process_cmds(&data, argc - 3, &argv[2], &stdinfd);
	tmp = ft_save(&data, argc[argv - 1], stdinfd);
	if (tmp != 0)
		status = tmp;
	if (error != NULL)
		return (ft_dprintf(STDERR_FILENO, "%s: %s: %s\n", data.name, argv[1],
				error), ft_close(&data, 0), 0);
	ft_close(&data, status);
}
