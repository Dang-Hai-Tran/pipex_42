/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:12:05 by datran            #+#    #+#             */
/*   Updated: 2023/05/02 13:39:19 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	close_fd(t_pipex *pipex)
{
	if (close(pipex->pipe_fd[0]) == -1)
		ft_perror("Close");
	if (close(pipex->pipe_fd[1]) == -1)
		ft_perror("Close");
	if (close(pipex->infile_fd) == -1)
		ft_perror("Close");
	if (close(pipex->outfile_fd) == -1)
		ft_perror("Close");
}

void	free_pipex(t_pipex *pipex)
{
	int		i;

	free(pipex->cmd);
	i = -1;
	while (pipex->cmd_args[++i] != NULL)
		free(pipex->cmd_args[i]);
	free(pipex->cmd_args);
}