/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:50:05 by datran            #+#    #+#             */
/*   Updated: 2023/05/02 13:50:15 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	check_args(int argc, char **argv, t_pipex *pipex)
{
	if (argc != 5)
		ft_error("Invalid number arguments");
	pipex->infile_fd = open(argv[1], O_RDONLY);
	pipex->outfile_fd = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if ((pipex->infile_fd < 0) | (pipex->outfile_fd < 0))
		ft_perror("Open");
}

static char	*find_env_path(char **envp)
{
	int		i;
	char	*path;

	i = -1;
	while (envp[++i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			path = envp[i];
			break ;
		}
	}
	return (path + 5);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex		pipex;

	check_args(argc, argv, &pipex);
	pipex.env_path = find_env_path(envp);
	if (pipe(pipex.pipe_fd) == -1)
		ft_perror("Pipe");
	pipex.pid1 = fork();
	pipex.pid2 = fork();
	if (pipex.pid1 < 0 || pipex.pid1 < 0)
		ft_perror("Fork");
	if (pipex.pid1 == 0)
		first_child(argv, envp, &pipex);
	if (pipex.pid2 == 0)
		second_child(argv, envp, &pipex);
	close_fd(&pipex);
	waitpid(pipex.pid2, NULL, 0);
	waitpid(pipex.pid1, NULL, 0);
	return (0);
}
