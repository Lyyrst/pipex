/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:19:51 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/03/11 12:54:06 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	free_struct(t_pipex *pipex)
{
	if (pipex)
	{
		if (pipex->path1)
			free(pipex->path1);
		if (pipex->path2)
			free(pipex->path2);
		if (pipex->cmd1)
			free_array(pipex->cmd1);
		if (pipex->cmd2)
			free_array(pipex->cmd2);
		if (pipex->fd_in != -1)
			close(pipex->fd_in);
		if (pipex->fd_out != -1)
			close(pipex->fd_out);
		if (pipex->p_fd[0] != -1)
			close(pipex->p_fd[0]);
		if (pipex->p_fd[1])
			close(pipex->p_fd[1]);
		free(pipex);
	}
}

void	exit_process(char *error, t_pipex *pipex, int success)
{
	if (pipex)
		free_struct(pipex);
	if (error)
		ft_putstr_fd(error, 2);
	if (success == 0)
		exit(EXIT_FAILURE);
	if (success == 1)
		exit(EXIT_SUCCESS);
}

void	command(t_pipex *pipex, char **envp, char **cmd, int n)
{
	if (n == 1)
	{
		if (execve(pipex->path1, cmd, envp) == -1)
			exit_process("first command fail\n", pipex, 0);
	}
	if (n == 2)
	{
		if (access(pipex->path2, F_OK | X_OK) == -1)
			exit_process("second command do fail\n", pipex, 0);
		else
		{
			if (execve(pipex->path2, cmd, envp) == -1)
				exit_process("seconde command fail\n", pipex, 0);
		}
	}
}
