/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:14:16 by datran            #+#    #+#             */
/*   Updated: 2023/03/24 15:49:04 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

static void	check(int argc, char **argv, char **envp, t_pipex *pipex)
{
	if (argc != 5)
		msg_error(ERR_NUMS_ARGS);
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
		msg_perror(ERR_INFILE);
	pipex->outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex->outfile < 0)
		msg_perror(ERR_OUTFILE);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	check(argc, argv, envp, &pipex);
	pipex.paths = find_path(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	if (pipe(pipex.tube) == -1)
		msg_perror(ERR_PIPE);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		first_redirect(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		second_redirect(pipex, argv, envp);
	close_pipes(&pipex);
	close_in_out(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	free_cmd_paths(&pipex);
	return (0);
}
