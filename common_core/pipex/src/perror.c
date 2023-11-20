/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:42:42 by sdabland          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:42 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

void	ft_perror(t_data *data, int myerror)
{
	char	*error;

	error = strerror(errno);
	if (myerror == PIPING_FAILED)
	{
		ft_dprintf(STDERR_FILENO, "%s: pipe error: %s\n", data->name, error);
		return ;
	}
	if (myerror == FORK_FAILED)
	{
		ft_dprintf(STDERR_FILENO, "%s: fork error: %s\n", data->name, error);
		return ;
	}
	if (myerror == CLOSE_FAILED)
	{
		ft_dprintf(STDERR_FILENO, "%s: close error: %s\n", data->name, error);
		return ;
	}
	if (myerror == WAITPID_FAILED)
	{
		ft_dprintf(STDERR_FILENO, "%s: waitpid error: %s\n", data->name, error);
		return ;
	}
}
