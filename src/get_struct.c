/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:19:45 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/03/11 13:54:02 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	init_pipex(t_pipex *pipex)
{
	if (!pipex)
		return ;
	pipex->cmd1 = 0;
	pipex->cmd2 = 0;
	pipex->path1 = 0;
	pipex->path2 = 0;
	pipex->fd_in = -1;
	pipex->fd_out = -1;
	pipex->p_fd[0] = -1;
	pipex->p_fd[1] = -1;
}

static void	get_cmd(char **argv, t_pipex *pipex)
{
	pipex->cmd1 = ft_split(argv[2], ' ');
	if (!pipex->cmd1 || !pipex->cmd1[0])
		exit_process("Allocution fail for cmd 1\n", pipex, 0);
	pipex->cmd2 = ft_split(argv[3], ' ');
	if (!pipex->cmd2 || !pipex->cmd2[0])
		exit_process("Allocution fail for cmd 2\n", pipex, 0);
}

static char	**get_envp_path(char **envp, t_pipex *pipex)
{
	int		i;
	char	*path;
	char	**ret;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = envp[i] + 5;
			break ;
		}
		i++;
	}
	ret = ft_split(path, ':');
	if (!ret)
		exit_process("An allocution fail while searching cmd path\n", pipex, 0);
	return (ret);
}

static void	get_path(char **envp, t_pipex *pipex, char **path, char *cmd)
{
	char	**cmd_paths;
	char	*tmp;
	int		i;
	int		n;

	i = 0;
	n = 0;
	cmd_paths = get_envp_path(envp, pipex);
	while (cmd_paths[i] && n == 0)
	{
		tmp = ft_strjoin(cmd_paths[i], "/");
		*path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(*path, F_OK | X_OK) == 0)
		{
			n = 1;
			break ;
		}
		free(*path);
		i++;
	}
	if (n == 0)
		*path = ft_strdup(cmd);
	free_array(cmd_paths);
}

t_pipex	*get_struct(char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	init_pipex(pipex);
	if (!pipex)
		exit_process("allocution fail\n", pipex, 0);
	pipex->fd_in = open(argv[1], O_RDONLY);
	if (pipex->fd_in == -1)
		exit_process("open infile fail\n", pipex, 0);
	pipex->fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex->fd_out == -1)
		exit_process("open outfile fail\n", pipex, 0);
	get_cmd(argv, pipex);
	get_path(envp, pipex, &pipex->path1, pipex->cmd1[0]);
	get_path(envp, pipex, &pipex->path2, pipex->cmd2[0]);
	return (pipex);
}
