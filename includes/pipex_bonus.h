/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:46:32 by datran            #+#    #+#             */
/*   Updated: 2023/05/02 14:18:50 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	int		infile_fd;
	int		outfile_fd;
	char	*env_path;
	int		pipe_fd[2];
	char	*cmd;
	char	**cmd_args;
	pid_t	pid1;
	pid_t	pid2;
}	t_pipex;

// error.c
void	ft_error(char *str);
void	ft_perror(char *str);

// childs.c
void	first_child(char **argv, char **envp, t_pipex *pipex);
void	second_child(char **argv, char **envp, t_pipex *pipex);

// close.c
void	close_fd(t_pipex *pipex);
void	free_pipex(t_pipex *pipex);

#endif
