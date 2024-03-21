/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:20:06 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/03/11 12:55:16 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	first_cmd(char **envp, t_pipex *pipex)
{
	close(pipex->p_fd[0]);
	dup2(pipex->fd_in, 0);
	dup2(pipex->p_fd[1], 1);
	close(pipex->p_fd[1]);
	close(pipex->fd_in);
	close(pipex->fd_out);
	command(pipex, envp, pipex->cmd1, 1);
}

static void	second_cmd(char **envp, t_pipex *pipex)
{
	close(pipex->p_fd[1]);
	dup2(pipex->fd_out, 1);
	dup2(pipex->p_fd[0], 0);
	close(pipex->p_fd[0]);
	close(pipex->fd_in);
	close(pipex->fd_out);
	command(pipex, envp, pipex->cmd2, 2);
}

static void	pipex(char **a, char **e)
{
	t_pipex	*p;

	p = get_struct(a, e);
	if (pipe(p->p_fd) == -1)
		exit_process("pipe fail\n", p, 0);
	p->p1 = fork();
	if (p->p1 == -1)
		exit_process("first fork fail\n", p, 0);
	if (p->p1 == 0)
		first_cmd(e, p);
	if (access(p->path2, X_OK | F_OK) == -1)
		waitpid(p->p1, NULL, 0);
	p->p2 = fork();
	if (p->p2 == -1)
		exit_process("second fork fail\n", p, 0);
	if (p->p2 == 0)
		second_cmd(e, p);
	close(p->p_fd[0]);
	close(p->p_fd[1]);
	waitpid(p->p1, NULL, 0);
	waitpid(p->p2, NULL, 0);
	exit_process(0, p, 1);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		exit_process("wrong size of arguments\n", NULL, 0);
	pipex(argv, envp);
	return (0);
}
