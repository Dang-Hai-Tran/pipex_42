/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:29:33 by datran            #+#    #+#             */
/*   Updated: 2023/05/02 16:11:24 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_paths(char ***paths)
{
	int		i;

	i = -1;
	while ((*paths)[++i] != NULL)
		free((*paths)[i]);
	free(*paths);
}

char	*get_full_path_cmd(char *path, char *cmd)
{
	char	**paths;
	char	*full_path_cmd;
	char	*tmp;
	int		i;

	paths = ft_split(path, ':');
	i = -1;
	while (paths[++i] != NULL)
	{
		tmp = ft_strjoin(paths[i], "/");
		full_path_cmd = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full_path_cmd, X_OK) == 0)
		{
			free_paths(&paths);
			return (full_path_cmd);
		}
		free(full_path_cmd);
	}
	free_paths(&paths);
	return (NULL);
}

void	first_child(char **argv, char **envp, t_pipex *pipex)
{
	if (dup2(pipex->pipe_fd[1], STDOUT_FILENO) == -1)
		ft_error("Dup2 pipe_fd_1 stdout in first child");
	if (close(pipex->pipe_fd[0]) == -1)
		ft_error("Close pipe_fd_0 in first child");
	if (dup2(pipex->infile_fd, STDIN_FILENO) == -1)
		ft_error("Dup2 infile_fd stdin in first child");
	pipex->cmd_args = ft_split(argv[2], ' ');
	pipex->cmd = get_full_path_cmd(pipex->env_path, pipex->cmd_args[0]);
	if (execve(pipex->cmd, pipex->cmd_args, envp) == -1)
	{
		free_pipex(pipex);
		ft_perror("Execve cmd in first child");
	}
	free_pipex(pipex);
}

void	second_child(char **argv, char **envp, t_pipex *pipex)
{
	if (dup2(pipex->pipe_fd[0], STDIN_FILENO) == -1)
		ft_error("Dup2 pipe_fd_0 stdin in second child");
	if (close(pipex->pipe_fd[1]) == -1)
		ft_error("Close pipe_fd_1 in second child");
	if (dup2(pipex->outfile_fd, STDOUT_FILENO) == -1)
		ft_error("Dup2 outfile stdout in second child");
	pipex->cmd_args = ft_split(argv[3], ' ');
	pipex->cmd = get_full_path_cmd(pipex->env_path, pipex->cmd_args[0]);
	if (execve(pipex->cmd, pipex->cmd_args, envp) == -1)
	{
		free_pipex(pipex);
		ft_perror("Execve in second child");
	}
	free_pipex(pipex);
}
