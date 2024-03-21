/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:20:16 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/03/08 16:20:16 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		p_fd[2];
	int		fd_in;
	int		fd_out;
	char	**cmd1;
	char	**cmd2;
	char	*path1;
	char	*path2;
	pid_t	p1;
	pid_t	p2;
}	t_pipex;

void	exit_process(char *error, t_pipex *pipex, int success);
t_pipex	*get_struct(char **argv, char **envp);
void	command(t_pipex *pipex, char **envp, char **cmd, int n);

#endif