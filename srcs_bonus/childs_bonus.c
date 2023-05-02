/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:29:33 by datran            #+#    #+#             */
/*   Updated: 2023/05/02 13:47:31 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
			break ;
		free(full_path_cmd);
	}
	i = -1;
	while (paths[++i] != NULL)
		free(paths[i]);
	free(paths);
	return (full_path_cmd);
}

void	first_child(char **argv, char **envp, t_pipex *pipex)
{
	if (close(pipex->pipe_fd[0]) == -1)
		ft_perror("Close");
	if (dup2(pipex->pipe_fd[1], STDOUT_FILENO) == -1)
		ft_perror("Dup2");
	if (dup2(pipex->infile_fd, STDIN_FILENO) == -1)
		ft_perror("Dup2");
	pipex->cmd_args = ft_split(argv[2], ' ');
	pipex->cmd = get_full_path_cmd(pipex->env_path, pipex->cmd_args[0]);
	if (execve(pipex->cmd, pipex->cmd_args, envp) == -1)
	{
		free_pipex(pipex);
		ft_perror("Execve");
	}
	free_pipex(pipex);
}

void	second_child(char **argv, char **envp, t_pipex *pipex)
{
	if (close(pipex->pipe_fd[1]) == -1)
		ft_perror("Close");
	if (dup2(pipex->pipe_fd[0], STDIN_FILENO) == -1)
		ft_perror("Dup2");
	if (dup2(pipex->outfile_fd, STDOUT_FILENO) == -1)
		ft_perror("Dup2");
	pipex->cmd_args = ft_split(argv[3], ' ');
	pipex->cmd = get_full_path_cmd(pipex->env_path, pipex->cmd_args[0]);
	if (execve(pipex->cmd, pipex->cmd_args, envp) == -1)
	{
		free_pipex(pipex);
		ft_perror("Execve");
	}
	free_pipex(pipex);
}
