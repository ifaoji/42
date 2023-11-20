/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_cmd_not_found(t_data *data, char *cmd)
{
	char	*error;

	if (data->paths[0] != NULL)
	{
		if (cmd == NULL)
			cmd = "";
		ft_dprintf(STDERR_FILENO,
			"%s: %s: command not found\n", data->name, cmd);
	}
	else
	{
		error = strerror(errno);
		ft_dprintf(STDERR_FILENO, "%s: %s: %s\n", data->name, cmd, error);
	}
}

static void	ft_close_pipes(int pipes[2])
{
	close(pipes[0]);
	close(pipes[1]);
}

static void	ft_child(t_data *data, char *cmd, int stdinfd, int pipes[2])
{
	char	*path;
	char	**args;

	args = ft_split(cmd, ' ');
	if (args == NULL)
		return (ft_perror(data, MALLOC_FAILED), ft_close(data, MALLOC_FAILED));
	path = NULL;
	if (args[0] != NULL)
		path = ft_find_cmd_path((const char **) data->paths, args[0]);
	if (path == NULL)
		return (ft_cmd_not_found(data, args[0]), ft_free_stra(args),
			ft_close_pipes(pipes), ft_close (data, 127));
	if (dup2(stdinfd, STDIN_FILENO) < 0 || dup2(pipes[1], STDOUT_FILENO) < 0)
		return (ft_close_pipes(pipes), close(stdinfd), free(path),
			ft_free_stra(args), ft_perror(data, PIPING_FAILED),
			ft_close(data, PIPING_FAILED));
	if (close(stdinfd) < 0)
		return (ft_close_pipes(pipes), free(path),
			ft_free_stra(args), ft_perror(data, CLOSE_FAILED),
			ft_close(data, CLOSE_FAILED));
	ft_close_pipes(pipes);
	execve(path, args, environ);
	return (free(path), ft_free_stra(args),
		ft_close(data, EXECVE_FAILED));
}

static int	ft_spawn_child(t_data *data, char *cmd, int stdinfd, int *stdoutfd)
{
	int		pipes[2];
	int		pid;

	if (pipe(pipes) == -1)
		return (ft_perror(data, PIPING_FAILED), -PIPING_FAILED);
	*stdoutfd = pipes[0];
	pid = fork();
	if (pid < 0)
		return (ft_perror(data, FORK_FAILED), -FORK_FAILED);
	if (pid == 0)
		ft_child(data, cmd, stdinfd, pipes);
	if (close(pipes[1]) < 0)
		return (ft_perror(data, CLOSE_FAILED), ft_close(data, CLOSE_FAILED),
			-CLOSE_FAILED);
	return (pid);
}

int	ft_process_cmds(t_data *data, int count, char **cmds, int *stdin)
{
	int		idx;
	int		tmp;
	int		pid;
	t_pids	*lst;

	pid = 0;
	idx = -1;
	while (++idx < count && pid >= 0)
	{
		pid = ft_spawn_child(data, cmds[idx], *stdin, &tmp);
		ft_add(data, pid);
		close(*stdin);
		*stdin = tmp;
	}
	lst = data->pids;
	while (lst)
	{
		waitpid(lst->pid, &tmp, 0);
		if (WIFEXITED(tmp))
			tmp = WEXITSTATUS(tmp);
		lst = lst->next;
	}
	if (pid < 0)
		return (-pid);
	return (tmp);
}
