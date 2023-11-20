/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

# include "../lib/libft/inc/libft.h"

extern char	**environ;

typedef enum e_exit_code
{
	MISSING_PATH_ENV,
	MISSING_ARGS,
	PIPING_FAILED,
	FORK_FAILED,
	MALLOC_FAILED,
	CMD_NOT_FOUND,
	CLOSE_FAILED,
	EXECVE_FAILED,
	WAITPID_FAILED,
	READ_ERROR,
}	t_exit_code;

typedef struct s_pids
{
	struct s_pids	*next;
	int				pid;
}	t_pids;

typedef struct s_data
{
	bool	heredoc;
	char	*name;
	char	**paths;
	t_pids	*pids;
}	t_data;

// add.c
void			ft_add(t_data *data, int pid);

// child.c
int				ft_process_cmds(t_data *data, int count,
					char **cmds, int *stdin);

// close.c
void			ft_close(t_data *data, enum e_exit_code code);

// env.c
const char		*ft_get_env(const char *name);

// paths.c
char			**ft_get_paths(void);
char			*ft_find_cmd_path(const char *paths[], const char *cmd);

// perror.c
void			ft_perror(t_data *data, int myerror);

#endif
